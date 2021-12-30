#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "config.h"
#include "Entity.h"
#include "FireballAnimation.h"

class Fireball : public Entity{
public:
    // Constructor
    Fireball( const sf::Vector2f pos, float speed, sf::Vector2f scale, float rotation );
    void updateKeyboard(sf::Time dt);

    void update( sf::Time dt );

    void rotateFireball( float angle );

    float getFireballRotation();

    void setBox();


private:
    sf::Texture startTex;

    sf::Vector2f fBox_scale {0.2, 0.4};
    sf::Vector2f fCirc_scale {1, 1};

    FireballAnimation fireballLeft;
    // FireballAnimation fireballRight;
    // FireballAnimation fireballUp;
    // FireballAnimation fireballDown;

    sf::Vector2f dir { 0.0f, 0.0f };
};