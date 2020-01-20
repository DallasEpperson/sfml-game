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

class Entity{
protected:
    sf::RectangleShape shape;
    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    virtual void move(const float& dt, const float x, const float y);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};