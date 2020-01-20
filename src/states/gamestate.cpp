#include "gamestate.hpp"

void GameState::initKeybinds(){
    std::ifstream inFile("config/gamestate-keybinds.ini");

    if (inFile.is_open()){
        std::string key = "";
        std::string keyCode = "";
        while(inFile >> key >> keyCode)
        {
            this->keybinds[key] = this->supportedKeys->at(keyCode);
        }
    }

    inFile.close();
}

GameState::GameState(
    sf::RenderWindow *window, 
    std::map<std::string, int>* supportedKeys,
    std::stack<State*>* states)
    : State(window, supportedKeys, states)
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
    this->updateMousePositions();
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    this->player.render(target);
}