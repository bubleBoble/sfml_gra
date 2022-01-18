#include "StartScreen.h"

Startscreen::Startscreen( float width, float height )
{   
    std::stringstream ss;
    ss << RESOURCE_PATH << "sansation.ttf";
    
    
    if(!font.loadFromFile( ss.str() ))
        log("can't load font [mainmenu]");

    this->background.setSize( {SC_WIDTH+0.f, SC_HEIGHT+0.f} );
    this->background.setFillColor(sf::Color(227, 221, 220, 160));

    // Resume
    mm[0].setFont(font);
    mm[0].setFillColor(sf::Color::White);
    mm[0].setString("player 1");
    mm[0].setCharacterSize(50);
    mm[0].setPosition( {
        SC_WIDTH/2 - mm[0].getGlobalBounds().width/2,
        SC_HEIGHT/3 - mm[0].getGlobalBounds().height/2,
    }); 

    // New game
    mm[1].setFont(font);
    mm[1].setFillColor(sf::Color::White);
    mm[1].setString("player 2");
    mm[1].setCharacterSize(50);
    mm[1].setPosition( {
        SC_WIDTH/2 - mm[0].getGlobalBounds().width/2,
        SC_HEIGHT/3 - mm[0].getGlobalBounds().height/2 + mm[0].getGlobalBounds().height + btnSpacing,
    }); 

    // Quit and save
    mm[2].setFont(font);
    mm[2].setFillColor(sf::Color::White);
    mm[2].setString("player 3");
    mm[2].setCharacterSize(50);
    mm[2].setPosition( {
        SC_WIDTH/2 - mm[0].getGlobalBounds().width/2,
        SC_HEIGHT/3 - mm[0].getGlobalBounds().height/2 + 2*mm[0].getGlobalBounds().height + 2*btnSpacing,
    }); 

    btnSelected = -1;
}

Startscreen::~Startscreen()
{
    ;
}

void Startscreen::draw( sf::RenderTarget* target )
{
    target->draw( background );
    for(sf::Text& i : mm)
    {
        target->draw(i);
    }
}

void Startscreen::moveup()
{
    if ( btnSelected - 1 >= 0)
    {
        mm[btnSelected].setFillColor(sf::Color::White);

        btnSelected--;
        if(btnSelected == -1)
            btnSelected = 2;
    
        mm[btnSelected].setFillColor(sf::Color::Blue);
    }
}

void Startscreen::movedown()
{
    if(btnSelected + 1 <= maxbtns)
    {
        mm[btnSelected].setFillColor(sf::Color::White);
        btnSelected++;

        if(btnSelected == 3 )
        {
            btnSelected = 0;
        }
        mm[btnSelected].setFillColor(sf::Color::Blue);
    }
}

int Startscreen::getSelected()
{
    /*
    0-input field
    1-start
    2-highscores
    */
   return btnSelected;
}

















