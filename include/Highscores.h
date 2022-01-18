#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "config.h"

#define maxMm 3

class Highscores
{
public:
    Highscores(float width, float height);
    ~Highscores();


    void draw( sf::RenderTarget* target );
    void moveup();
    void movedown();

    int getMMselected();

private:
    sf::RectangleShape background;
    int mmSelecetd;
    sf::Font font;
    sf::Text mm[maxMm];
    
    float btnSpacing {20};

};
