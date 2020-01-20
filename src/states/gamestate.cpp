#include "gamestate.hpp"

GameState::GameState(sf::RenderWindow *window)
    : State(window)
{
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
}

void GameState::update(const float &dt)
{
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget *target)
{
    if (target)
    {
        this->player.render(target);
    }
    else
    {
        this->player.render(this->window);
    }
}