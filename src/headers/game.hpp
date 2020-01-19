#pragma once

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;

    void initWindow();
public:
    Game();
    virtual ~Game();

    void updateSFMLEvents();
    void update();
    void render();
    void run();
};