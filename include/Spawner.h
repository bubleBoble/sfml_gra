#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <cmath>

#include "config.h"

#include "Player.h"
#include <iostream>
#include "Entity.h"
#include "FireBall.h"


class Spawner
{
protected:
    sf::Vector2f spawnerPosition;
    float spawnerRotation;
    float timeDelay {0.5};
    int side;

    std::vector<Fireball*> fireballs;

    sf::CircleShape* spawnerShape;

    sf::Clock* clockFbDelay;

    sf::Vector2f fbScale {0.23f, 0.23f} ;

    float spawnerSpeed;

public:
    Spawner(sf::RenderTarget* target, float rotation, sf::Vector2f pos, sf::Vector2f fbScale, float _speed, float _delay); // Side -> 0-left, 1-right, 2-top, 3-bot
    ~Spawner();

    void update( float str1, float str2 );

    sf::Vector2f getSpawnderPos();

    // void update(sf::Time dt, sf::FloatRect player, float speed, sf::Vector2f scale, float rotation, float _delay);
    void update(sf::Time dt, Player& player, float speed, sf::Vector2f scale, float rotation, float _delay);

    void draw(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);

    void setTimeDelay( float _timeDelay );

    bool checkCollisionPlayer( sf::FloatRect player );

    void move(const float dirX, const float dirY, sf::Time dt);

    sf::Vector2f dir;
    void updateKeyboard(sf::Time dt);
    void moveLeftRight(sf::Time dt);
    void moveUpDown(sf::Time dt);
};