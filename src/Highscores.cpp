#include "Highscores.h"


Highscores::Highscores( float width, float height )
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
    mm[0].setString("1. Player 1");
    mm[0].setCharacterSize(50);
    mm[0].setPosition( {
        SC_WIDTH/2 - mm[0].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[0].getGlobalBounds().height/2,
    }); 

    // New game
    mm[1].setFont(font);
    mm[1].setFillColor(sf::Color::White);
    mm[1].setString("2. Player 2");
    mm[1].setCharacterSize(50);
    mm[1].setPosition( {
        SC_WIDTH/2 - mm[1].getGlobalBounds().width/2,
        SC_HEIGHT/5- mm[0].getGlobalBounds().height/2 + mm[0].getGlobalBounds().height + btnSpacing,
    }); 

    // Quit and save
    mm[2].setFont(font);
    mm[2].setFillColor(sf::Color::White);
    mm[2].setString("3. Player 3");
    mm[2].setCharacterSize(50);
    mm[2].setPosition( {
        SC_WIDTH/2 - mm[2].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[1].getGlobalBounds().height/2 + 2*mm[0].getGlobalBounds().height + 2*btnSpacing,
    }); 
}


Highscores::~Highscores()
{
    ;
}

void Highscores::draw( sf::RenderTarget* target )
{
    target->draw( background );
    for(sf::Text& i : mm)
    {
        target->draw(i);
    }
}

void Highscores::moveup()
{
    if ( mmSelecetd - 1 >= 0)
    {
        mm[mmSelecetd].setFillColor(sf::Color::White);

        mmSelecetd--;
        if(mmSelecetd == -1)
            mmSelecetd = 2;
    
        mm[mmSelecetd].setFillColor(sf::Color::Blue);
    }
}

void Highscores::movedown()
{
    if(mmSelecetd + 1 <= maxMm)
    {
        mm[mmSelecetd].setFillColor(sf::Color::White);
        mmSelecetd++;

        if(mmSelecetd == 7 )
        {
            mmSelecetd = 0;
        }
        mm[mmSelecetd].setFillColor(sf::Color::Blue);
    }
}

int Highscores::getMMselected()
{
    /*
    0-resume
    1-new game
    2-save
    3-exit
    */
   return mmSelecetd;
}


