#pragma once

#include "../entities/entity.hpp"

class State{
protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    std::vector<sf::Texture*> textures;
    bool quit;

    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;

    virtual void checkForQuit();
    virtual void endState() = 0;
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};