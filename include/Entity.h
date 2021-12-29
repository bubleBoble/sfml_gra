#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"

class Entity 
{
protected:
    sf::Vector2f shapeCenter;
    sf::FloatRect shapeSize;

    sf::RectangleShape entityBox;
    sf::CircleShape entityCircle;

    float m_speed;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f spriteSize;

    void init( sf::Vector2f _pos, sf::Vector2f _scale, float _speed ); 

public:

    /* Constructor & destructor
    ********************/
    Entity( sf::Vector2f entityPos, sf::Vector2f entityScale, float entitySpeed );  
    Entity();
    ~Entity();

    /* Render & update
    ********************/
    void move_(const float dirX, const float dirY, sf::Time dt);
    void updateKeyboard( sf::Time dt );             // Update ent. position
    void render(sf::RenderTarget& target);                // Render ent. to the target

    /* Getters & setters
    ********************/
    sf::Vector2f getPosCenter();
    sf::Vector2f getSpriteSize();
    void setSprite(std::string textureName, int tex_x, int tex_y, int tex_width, int tex_height);
    void setSpriteScale(float scale_x, float scale_y);
    void setSpriteSpeed(float speed);
    void setSpritePos(sf::Vector2f pos);

    void setEntityBox(sf::Vector2f scale);
    void setEntityCircle();
};
