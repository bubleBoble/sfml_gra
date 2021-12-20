#include "Hud.h"

void Hud::initHud( ) 
{   
//     std::string fontPath = RESOURCE_PATH + "sansation.ttf";
//     font.loadFromFile(fontPath);

    lTop = new sf::Text;
    rTop = new sf::Text;

}

Hud::Hud( sf::RenderTarget& target  )
{
    initHud();
}

Hud::~Hud() 
{
    delete ltop;
    delete rTop;
}