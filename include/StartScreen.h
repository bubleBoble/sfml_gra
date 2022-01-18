#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "config.h"

#define maxbtns 3

class Startscreen
{
public:
    Startscreen(float width, float height);
    ~Startscreen();


    void draw( sf::RenderTarget* target );
    void moveup();
    void movedown();

    int getSelected();

    void setInput( std::string input );

private:
    sf::RectangleShape background;
    int btnSelected;
    sf::Font font;
    sf::Text mm[maxbtns];
    
    float btnSpacing {20};

};
