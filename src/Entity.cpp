#include "Entity.h"

void Entity::init( sf::Vector2f _pos, sf::Vector2f _size, float _speed ) 
{   
    this-> m_speed = _speed;
    this->m_shape.setPosition(
        SC_WIDTH/2 - _size.x/2 + _pos.x, 
        SC_HEIGHT/2 - _size.y/2 - _pos.y);
    this->m_shape.setSize(_size);
    this->m_shape.setFillColor(sf::Color::White);
}

Entity::Entity( sf::Vector2f entityPos, sf::Vector2f entitySize, float entitySpeed)
{
    init(entityPos, entitySize, entitySpeed);
}

Entity::~Entity()
{

}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->m_shape);
}

sf::Vector2f Entity::getPosCenter() 
{
    sf::Vector2f pos = this->m_shape.getPosition();
    pos.x = pos.x + this->m_shape.getSize().x / 2;
    pos.y = pos.y + this->m_shape.getSize().y / 2;
    return pos;
}

void Entity::move_(const float dirX, const float dirY, sf::Time dt)
{
    this->m_shape.move(
        this->m_speed * dirX * dt.asSeconds(),
        this->m_speed * dirY * dt.asSeconds()
        );
}

void Entity::updateKeyboard(sf::Time dt)
{
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move_(0.f, -1.f, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move_(-1.f, 0.f, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move_(0.f, 1.f, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move_(1.f, 0.f, dt);
}



