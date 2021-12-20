#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"

class Entity 
{
protected:
    sf::RectangleShape m_shape;

    sf::Vector2f shapeCenter;
    sf::FloatRect shapeSize;

    float m_speed;

    /*
    Sets entity position */
    void init( sf::Vector2f _pos, sf::Vector2f _size, float _speed ); 

public:
    Entity( sf::Vector2f entityPos, sf::Vector2f entitySize, float entitySpeed );  
    ~Entity();

    sf::Vector2f getPosCenter();

    void move_(const float dirX, const float dirY, sf::Time dt);

    void updateKeyboard( sf::Time dt );             // Update ent. position
    void render(sf::RenderTarget& target);                // Render ent. to the target


    
};
