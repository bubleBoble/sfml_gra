#include "Hud.h"

Hud::Hud()
{
    std::string fontpath = RESOURCE_PATH;
    fontpath += "sansation.ttf";
    if ( !this->font.loadFromFile(fontpath) )
        log("can't load font");

    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(50);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setOutlineThickness(1);
    this->uiText.setOutlineColor(sf::Color::Cyan);
    this->uiText.setString("NONE");
}

void Hud::update( int* points, int* health, std::string playername )
{
    std::stringstream ss;

    ss << "Points: " << *points << std::endl 
    <<  "Health: " << *health << std::endl
    << playername;

    this->uiText.setString( ss.str() );
}

void Hud::render( sf::RenderTarget* target )
{
    target->draw( this->uiText );
}