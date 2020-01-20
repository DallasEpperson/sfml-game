#pragma once

#include "gamestate.hpp"
#include "../button.hpp"

class MainMenuState : public State {
private:
    sf::RectangleShape background;
    sf::Font font;
    std::map<std::string, Button*> buttons;
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    void endState();
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};