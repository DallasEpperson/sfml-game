#include "gamestate.hpp"

void GameState::initKeybinds(){
    this->keybinds["CLOSE"] = this->supportedKeys->at("ESC");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initKeybinds();
}

GameState::~GameState()
{
}

void GameState::endState()
{
    std::cout << "GameState::endState" << std::endl;
}

void GameState::updateInput(const float &dt)
{
    this->checkForQuit();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))){
        this->player.move(dt, -1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))){
        this->player.move(dt, 1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))){
        this->player.move(dt, 0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))){
        this->player.move(dt, 0.f, 1.f);
    }
}

void GameState::update(const float &dt)
{
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    this->player.render(target);
}