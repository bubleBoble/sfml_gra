#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "config.h"

#define maxMm 7

class Mainmenu
{
public:
    Mainmenu(float width, float height);
    ~Mainmenu();


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
