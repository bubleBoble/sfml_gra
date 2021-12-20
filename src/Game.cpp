#include "Game.h"
#include "config.h"

void Game::initWindow() 
{
    this->window = new sf::RenderWindow( sf::VideoMode(SC_WIDTH, SC_HEIGHT), "GNOP", sf::Style::Fullscreen, settings );
}

Game::Game()
{
    settings.antialiasingLevel = 8;
    this->initWindow();

    /* Test player object
    ****************/
    sf::Vector2f playerPos = sf::Vector2f(0, 0);
    sf::Vector2f playerSize = sf::Vector2f(50, 50);
    player1 = new Player(playerPos, playerSize, 1000); 
}

Game::~Game()
{
    delete this->window;

    /* Delete game objects
    **************************/
    delete this->player1;
}

void Game::run() 
{
    // Main game loop
    while (this->window->isOpen())
    {

        this->pollEvents();

        dt = clock.restart();
        
        this->update(dt);

        this->render(); 

    }
}

void Game::update(sf:: Time dt)
{
    player1->updateKeyboard(dt);
}

void Game::render()
{
    this->window->clear();

    // Drawing coordinates
    drawCoordinates(*window);
    
    //  Drawing game objects
    player1->render(*this->window);

    this->window->display();
}

void Game::pollEvents() 
{
    while (this->window->pollEvent(ev)) 
    {
        if ((ev.type == sf::Event::Closed) || (ev.key.code == sf::Keyboard::Escape))
            this->window->close();
    }

}

void Game::drawCoordinates(sf::RenderTarget& target){
    OxLine = sf::RectangleShape(sf::Vector2f(SC_WIDTH, 2));
    OyLine = sf::RectangleShape(sf::Vector2f(SC_HEIGHT, 2));

    OxLine.setPosition(0, SC_HEIGHT/2);
    OxLine.setFillColor(sf::Color(255, 255, 255, 50));
    OyLine.setPosition(SC_WIDTH/2, 0);
    OyLine.setFillColor(sf::Color(255, 255, 255, 50));
    OyLine.rotate(90);

    target.draw(OxLine);
    target.draw(OyLine);
}