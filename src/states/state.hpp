#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class State{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture*> textures;

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void endState() = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};