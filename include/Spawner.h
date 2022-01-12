#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include "config.h"

#include <iostream>

#include "FireBall.h"


class Spawner
{
protected:
    sf::Vector2f spawnerPosition;
    float timeDelay;
    int side;

    std::vector<Fireball> fireballs;

    sf::CircleShape* spawnerShape;

    sf::Clock* clock;

public:
    Spawner(sf::RenderTarget* target, int rotation); // Side -> 0-left, 1-right, 2-top, 3-bot
    ~Spawner();

    void update( float str1, float str2 );

    sf::Vector2f getSpawnderPos();

    void update(sf::Time dt);
    void draw(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};