#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "config.h"
#include "Entity.h"
// #include "Animation.h"
#include "animation2xxx.h"

class Player : public Entity{
public:
    // Constructor
    Player( const sf::Vector2f pos, float speed, sf::Vector2f scale );
    void updateKeyboard(sf::Time dt);

    void update( sf::Time dt );

private:
    Animation rightWalk, leftWalk, upWalk, downWalk;
    sf::Texture frontTex;
    sf::Vector2f dir { 0.0f, 0.0f };
};