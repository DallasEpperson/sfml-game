#include "gamestate.hpp"

GameState::GameState(sf::RenderWindow* window)
    : State(window){

}

GameState::~GameState(){

}

void GameState::endState(){

}

void GameState::update(const float& dt){
    std::cout << "GameState::update" << std::endl;
}

void GameState::render(sf::RenderTarget* target){

}