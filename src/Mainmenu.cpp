#include "Mainmenu.h"

Mainmenu::Mainmenu( float width, float height )
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
    mm[0].setString("Resume");
    mm[0].setCharacterSize(50);
    mm[0].setPosition( {
        SC_WIDTH/2 - mm[0].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[0].getGlobalBounds().height/2,
    }); 

    // New game
    mm[1].setFont(font);
    mm[1].setFillColor(sf::Color::White);
    mm[1].setString("New game");
    mm[1].setCharacterSize(50);
    mm[1].setPosition( {
        SC_WIDTH/2 - mm[1].getGlobalBounds().width/2,
        SC_HEIGHT/5- mm[0].getGlobalBounds().height/2 + mm[0].getGlobalBounds().height + btnSpacing,
    }); 

    // Quit and save
    mm[2].setFont(font);
    mm[2].setFillColor(sf::Color::White);
    mm[2].setString("Save");
    mm[2].setCharacterSize(50);
    mm[2].setPosition( {
        SC_WIDTH/2 - mm[2].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[1].getGlobalBounds().height/2 + 2*mm[0].getGlobalBounds().height + 2*btnSpacing,
    }); 

    // Exit
    mm[3].setFont(font);
    mm[3].setFillColor(sf::Color::White);
    mm[3].setString("Exit");
    mm[3].setCharacterSize(50);
    mm[3].setPosition( {
        SC_WIDTH/2 - mm[3].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[2].getGlobalBounds().height/2 + 3*mm[0].getGlobalBounds().height + 3*btnSpacing,
    }); 

    // player1
    mm[4].setFont(font);
    mm[4].setFillColor(sf::Color::White);
    mm[4].setString("change to player 1");
    mm[4].setCharacterSize(50);
    mm[4].setPosition( {
        SC_WIDTH/2 - mm[4].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[3].getGlobalBounds().height/2 + 4*mm[0].getGlobalBounds().height + 4*btnSpacing,
    }); 
    // player2
    mm[5].setFont(font);
    mm[5].setFillColor(sf::Color::White);
    mm[5].setString("change to player 2");
    mm[5].setCharacterSize(50);
    mm[5].setPosition( {
        SC_WIDTH/2 - mm[5].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[4].getGlobalBounds().height/2 + 5*mm[0].getGlobalBounds().height + 5*btnSpacing,
    }); 
    // player3
    mm[6].setFont(font);
    mm[6].setFillColor(sf::Color::White);
    mm[6].setString("change to player 3");
    mm[6].setCharacterSize(50);
    mm[6].setPosition( {
        SC_WIDTH/2 - mm[6].getGlobalBounds().width/2,
        SC_HEIGHT/5 - mm[5].getGlobalBounds().height/2 + 6*mm[0].getGlobalBounds().height + 6*btnSpacing,
    }); 

    mmSelecetd = -1;
}

Mainmenu::~Mainmenu()
{
    ;
}

void Mainmenu::draw( sf::RenderTarget* target )
{
    target->draw( background );
    for(sf::Text& i : mm)
    {
        target->draw(i);
    }
}

void Mainmenu::moveup()
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

void Mainmenu::movedown()
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

int Mainmenu::getMMselected()
{
    /*
    0-resume
    1-new game
    2-save
    3-exit
    */
   return mmSelecetd;
}

















