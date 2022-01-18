#include <SFML/Graphics.hpp>
#include <sstream>

#include "config.h"

class Hud 
{
public:
    Hud();

    void update( int* points, int* health, std::string playername);
    void render( sf::RenderTarget* target );

private:
    sf::Font font;
    sf::Text uiText;

   
};