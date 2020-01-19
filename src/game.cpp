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

Game::Game(){
    this->initWindow();
}

Game::~Game(){
    delete this->window;
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
}

void Game::render(){
    this->window->clear();
    this->window->display();
}

void Game::run(){
    while (this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}