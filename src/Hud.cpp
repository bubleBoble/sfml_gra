#include "Hud.h"

void Hud::initHud( sf::Vector2u _bounds ) 
{   
    std::string fontPath = RESOURCE_PATH;
    fontPath += "sansation.ttf";
    if (!font.loadFromFile( fontPath ))
        return;
    
    font.loadFromFile(fontPath);

    lTop = new sf::Text;
    rTop = new sf::Text;

    lTop->setFont( font );
    lTop->setCharacterSize( 30 );
    lTop->setPosition( 20, 20 );
    lTop->setFillColor( sf::Color::Black );

    rTop->setFont(font);
    rTop->setCharacterSize( 30 );
    rTop->setPosition( 20, this->lTop->getGlobalBounds().height+50 );
    rTop->setFillColor( sf::Color::Black );
}

Hud::Hud( sf::RenderTarget* target  )
{   
    this->bounds = target->getSize();
    initHud( bounds );
}

Hud::~Hud() 
{
    delete this->lTop;
    delete this->rTop;
}

void Hud::render( sf::RenderTarget* target ) 
{
    target->draw( *lTop );
    target->draw( *rTop );
}

void Hud::update( float str1, float str2 ) 
{
    this->lTop->setString( "collisions :  " + std::to_string( (int)str1) );
    this->rTop->setString( "life       :  " + std::to_string( (int)str2) );
}