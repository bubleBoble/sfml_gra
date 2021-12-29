#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "config.h"


class Hud
{
protected:
    sf::Text* lTop;
    sf::Text* rTop;
    sf::Font font;

    sf::Vector2u bounds;
    sf::Vector2f margins;

    void initHud( sf::Vector2u _bounds );
public:
    Hud( sf::RenderTarget* target );
    ~Hud();

    void render( sf::RenderTarget* target );
    void update( float str1, float str2 );
};