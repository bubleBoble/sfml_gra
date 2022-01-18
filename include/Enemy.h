#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "config.h"


class Enemy 
{
public:
    Enemy( float _enemySpawnTimerMax, int _maxEnemies);
    ~Enemy();

    void update( 
        int* health,
        bool* mouseHeldDown,
        int* points,
        sf::Vector2f* mousePositionView,
        sf::Vector2f playerPos );
    void render( sf::RenderTarget* target );

    std::vector<sf::CircleShape> getEnemies();        // size_t to alias do unsigned int

private:
    sf::CircleShape shape;

    std::vector <sf::CircleShape> enemies;

    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    sf::Vector2f dir {0.f, 1.f};

    void initEnemies();
};