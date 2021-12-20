#include "Player.h"


Player::Player(sf::Vector2f pos, sf::Vector2f size, float speed)
: Entity(pos, size, speed)
{
   this->m_shape.setFillColor(sf::Color::Red);
}