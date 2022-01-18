#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "Animation.h"

class Player 
{
private:
    sf::RectangleShape shape;
    sf::Vector2f playerPosCenter;
    sf::Sprite sprite;
    sf::Texture texture;

    Animation rightWalk, leftWalk, upWalk, downWalk;

    float speed;

    sf::Vector2f dir;

    int health;

public:
    std::string name;

    Player( int _health );
    ~Player(); 

    void move( sf::Vector2f* dir, sf::Time* dt );
    void update( sf::Time* dt );
    void render( sf::RenderTarget* target );

    sf::Vector2f getPosCenter();
};