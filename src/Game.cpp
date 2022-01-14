#include "Game.h"
#include "config.h"

void Game::initWindow() 
{
    // Full screen
    // this->window = new sf::RenderWindow( sf::VideoMode(SC_WIDTH, SC_HEIGHT), "GNOP", sf::Style::Fullscreen, settings );

    // Do debuga
    this->window = new sf::RenderWindow( sf::VideoMode(SC_WIDTH, SC_HEIGHT), "GNOP", sf::Style::None, settings );
}

Game::Game()
{
    settings.antialiasingLevel = 8;
    this->initWindow();

    clockKolizja = new sf::Clock();

    /* Test player object
    ****************/
    player = new Player({500, 500}, 500, {10, 10});
    /* Test hud */
    hud = new Hud(window);
    
    float r = 250;
    for (int i=0; i<1; i++)
    {
        topSpawners.push_back( new Spawner(this->window, 0, {r, 0}) );
        r+=200;
    }

    topSpawners[0]->setTimeDelay( 1 );

}

Game::~Game()
{
    delete this->window;

    /* Delete game objects
    **************************/
    delete this->player;
    delete this->hud;

    for (auto& i : topSpawners)
    {
        delete i;
    }
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

void Game::update(sf::Time dt)
{
    player->updateKeyboard(dt);
    player->update( dt );
    
    for (auto& i : topSpawners)
    {
        i->update( dt );        
        if ( clockKolizja->getElapsedTime().asSeconds() > 1 )
        {
            if ( i->checkCollisionPlayer( this->player->getBox() ) )
            {
                this->collisions += 1;
                this->life -= 1;
                clockKolizja->restart();
            }
        }
    }

    this->hud->update( this->collisions, this->life );
}

void Game::render()
{
    this->window->clear( sf::Color::White );

    // Drawing coordinates
    drawCoordinates(*window);
    
    //  Drawing game objects
    player->render(*this->window); 


    for (auto& i : topSpawners)
    {
        i->render(*this->window);
    }

    hud->render(this->window);

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
    OxLine.setFillColor(sf::Color(0, 0, 0, 50));
    OyLine.setPosition(SC_WIDTH/2, 0);
    OyLine.setFillColor(sf::Color(0, 0, 0, 50));
    OyLine.rotate(90);

    target.draw(OxLine);
    target.draw(OyLine);
}