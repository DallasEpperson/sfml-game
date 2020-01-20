#include "headers/game.hpp"

void Game::initWindow(){
    std::ifstream inFile("config/window.ini");
    std::string title = "SFML game";
    sf::VideoMode windowBounds(800, 600);
    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = false;
    if (inFile.is_open()){
        std::getline(inFile, title);
        inFile >> windowBounds.width >> windowBounds.height;
        inFile >> framerateLimit;
        inFile >> verticalSyncEnabled;
    }
    inFile.close();

    this->window = new sf::RenderWindow(windowBounds, title);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initStates(){
    this->states.push(new GameState(this->window));
}

Game::Game(){
    this->initWindow();
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