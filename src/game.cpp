#include "headers/game.hpp"

void Game::initVariables(){
    this->window = nullptr;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow(){
    std::ifstream inFile("config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "SFML game";
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = false;
    unsigned int antialiasingLevel = 0;

    if (inFile.is_open()){
        std::getline(inFile, title);
        inFile >> windowBounds.width >> windowBounds.height;
        inFile >> this->fullscreen;
        inFile >> framerateLimit;
        inFile >> verticalSyncEnabled;
        inFile >> antialiasingLevel;
    }
    inFile.close();

    this->windowSettings.antialiasingLevel = antialiasingLevel;
    
    if(this->fullscreen)
    {
        windowBounds = sf::VideoMode::getDesktopMode(); //TODO depperson if set manually, results in crash. Y Tho?
        this->window = new sf::RenderWindow(windowBounds, title, sf::Style::Fullscreen, this->windowSettings);
    }
    else
    {
        this->window = new sf::RenderWindow(windowBounds, title, sf::Style::Titlebar | sf::Style::Close, this->windowSettings);
    }

    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initStates(){
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

void Game::initKeys(){
    std::ifstream inFile("config/supported-keys.ini");

    if (inFile.is_open()){
        std::string key = "";
        int keyValue = 0;
        while(inFile >> key >> keyValue)
        {
            this->supportedKeys[key] = keyValue;
        }
    }

    inFile.close();
}

Game::Game(){
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game(){
    delete this->window;

    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Game::endApplication(){
    std::cout << "Exiting application." << std::endl;
}

void Game::updateDt(){
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents(){
    while(this->window->pollEvent(this->sfEvent)){
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }else{
        this->endApplication();
        this->window->close();
    }
}

void Game::render(){
    this->window->clear();

    if(!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run(){
    while (this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}