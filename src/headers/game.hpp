#pragma once

#include "../states/gamestate.hpp"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;
    sf::Clock dtClock;
    float dt;
    std::stack<State*> states;

    void initWindow();
    void initStates();

public:
    Game();
    virtual ~Game();

    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};