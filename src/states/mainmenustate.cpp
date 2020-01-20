#include "mainmenustate.hpp"

void MainMenuState::initFonts()
{
    //todo get this from system's default instead
    if(!this->font.loadFromFile("./fonts/FreeMono.ttf")){
        throw("ERROR: MainMenuState could not load font");
    }
}

void MainMenuState::initKeybinds()
{
    std::ifstream inFile("config/mainmenustate-keybinds.ini");

    if (inFile.is_open())
    {
        std::string key = "";
        std::string keyCode = "";
        while (inFile >> key >> keyCode)
        {
            this->keybinds[key] = this->supportedKeys->at(keyCode);
        }
    }

    inFile.close();
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
        &this->font, "New Game",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
        &this->font, "Quit",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(
    sf::RenderWindow *window, 
    std::map<std::string, int> *supportedKeys,
    std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

void MainMenuState::endState()
{
    std::cout << "MainMenuState::endState" << std::endl;
}

void MainMenuState::updateInput(const float &dt)
{
    this->checkForQuit();
}

void MainMenuState::updateButtons()
{
    for (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit = true;
    }
}

void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->draw(this->background);
    this->renderButtons(target);
}