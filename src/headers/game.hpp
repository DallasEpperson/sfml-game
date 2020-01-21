#pragma once

#include "../states/mainmenustate.hpp"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullscreen;
    sf::Clock dtClock;
    float dt;
    std::stack<State*> states;
    std::map<std::string, int> supportedKeys;

    void initVariables();
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