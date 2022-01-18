#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

#include "config.h"
#include "Enemy.h"

class Bullet {

public:
    sf::CircleShape shape;
    sf::Vector2f currVelocity;
    float maxSpeed;
    float radius;

    std::vector<sf::CircleShape> bullets;

    /**/
    sf::Vector2f playerCenter;
    sf::Vector2f mousePos;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    Bullet(  );
    ~Bullet();

};