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

    void initHud();
public:
    Hud( sf::RenderTarget& target );
    ~Hud();

    void render();
    void update();
};