#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Entity.h"

class Player : public Entity 
{
public:
    Player(sf::Vector2f pos, sf::Vector2f size, float speed);
};
