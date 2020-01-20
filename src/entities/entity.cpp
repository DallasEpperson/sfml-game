#include "entity.hpp"

Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.f;
}

Entity::~Entity()
{

}

void Entity::move(const float &dt, const float dx, const float dy)
{
    this->shape.move(dx * this->movementSpeed * dt, dy * this->movementSpeed * dt);
}

void Entity::update(const float & dt){
    
}

void Entity::render(sf::RenderTarget* target){
    target->draw(this->shape);
}