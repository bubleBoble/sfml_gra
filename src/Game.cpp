#include "Game.h"
#include "config.h"

void Game::initWindow() 
{
    // Full screen
    // this->window = new sf::RenderWindow( sf::VideoMode(SC_WIDTH, SC_HEIGHT), "GNOP", sf::Style::Fullscreen, settings );

    // Do debuga
    this->window = new sf::RenderWindow( sf::VideoMode(SC_WIDTH, SC_HEIGHT), "GNOP", sf::Style::Titlebar, settings );
}

Game::Game()
{
    settings.antialiasingLevel = 8;
    this->initWindow();

    /* Test player object
    ****************/
    player = new Player({500, 500}, 500, {10, 10});
    /* Test hud */
    hud = new Hud(window);
    /* Fireball */
    // RL_fireball = new Fireball( {900, 400}, 50, {0.3, 0.3}, 0 );
    // LR_fireball = new Fireball( {900, 400}, 50, {0.3, 0.3}, 180 );
    // UD_fireball = new Fireball( {900, 400}, 50, {0.3, 0.3}, -90 );
    // DU_fireball = new Fireball( {900, 400}, 20, {0.3, 0.3}, 90 );
    /* Spawner */
    spawner = new Spawner(this->window, 0);
}

Game::~Game()
{
    delete this->window;

    /* Delete game objects
    **************************/
    delete this->player;
    delete this->hud;
    // delete this->RL_fireball;
    // delete this->LR_fireball;
    // delete this->UD_fireball;
    // delete this->DU_fireball;

    delete this->spawner;
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

    // // RL_fireball->updateKeyboard(dt);
    // RL_fireball->update( dt );
    // // LR_fireball->updateKeyboard(dt);
    // LR_fireball->update( dt );
    // // UD_fireball->updateKeyboard(dt);
    // UD_fireball->update( dt );
    // // DU_fireball->updateKeyboard(dt);
    // DU_fireball->update( dt );

    this->hud->update( player->getPosCenter().x, player->getPosCenter().y );
    this->spawner->update( dt );
}

void Game::render()
{
    this->window->clear( sf::Color::White );

    // Drawing coordinates
    drawCoordinates(*window);
    
    //  Drawing game objects
    player->render(*this->window); 

    // RL_fireball->render(*this->window);
    // LR_fireball->render(*this->window);
    // UD_fireball->render(*this->window);
    // DU_fireball->render(*this->window);

    spawner->render(*this->window);

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