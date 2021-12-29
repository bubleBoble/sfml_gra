#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "config.h"
#include "Entity.h"
#include "FireballAnimation.h"

class Fireball : public Entity{
public:
    // Constructor
    Fireball( const sf::Vector2f pos, float speed, sf::Vector2f scale );
    void updateKeyboard(sf::Time dt);

    void update( sf::Time dt );

    void rotateFireball( float angle );

private:
    FireballAnimation fireballLeft;
    FireballAnimation fireballRight;
    FireballAnimation fireballUp;
    FireballAnimation fireballDown;

    sf::Vector2f dir { 0.0f, 0.0f };
};