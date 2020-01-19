#pragma once

#include "state.hpp"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;
    sf::Clock dtClock;
    float dt;

    void initWindow();

public:
    Game();
    virtual ~Game();

    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};