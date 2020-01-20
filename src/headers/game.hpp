#pragma once

#include "../states/gamestate.hpp"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;
    sf::Clock dtClock;
    float dt;
    std::stack<State*> states;
    std::map<std::string, int> supportedKeys;

    void initWindow();
    void initStates();
    void initKeys();

public:
    Game();
    virtual ~Game();

    void endApplication();
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};