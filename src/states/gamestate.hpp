#pragma once

#include "state.hpp"

class GameState : public State {
private:
    Entity player;

    void initKeybinds();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~GameState();

    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};