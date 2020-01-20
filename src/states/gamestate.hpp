#pragma once

#include "state.hpp"

class GameState : public State {
private:

public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};