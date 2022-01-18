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
    
    srand (time(NULL));
    // initLevelSettings( 0 );

    level = 0;
    // initLevelSettings(level);
}

Game::~Game()
{
    delete this->window;

    /* Delete game objects
    **************************/
    delete this->player;
    delete this->hud;

    // delete spawner

    // for (auto& i : levelSpawners)
    // {
    //     delete i;
    // }
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
    
 
    // for (auto& i : levelSpawners)
    // {
    //     randomFireballspeed = randomRangefloat(500, 1500);
    //     i->update(dt, *this->player, randomFireballspeed, {0.23, 0.23}, 0, 1.5);
    // }

    this->hud->update( this->collisions, player->life );
}

void Game::render()
{
    this->window->clear( sf::Color::White );

    // Drawing coordinates
    drawCoordinates(*window);
    
    //  Drawing game objects
    player->render(*this->window); 

    // for (auto& i : levelSpawners)
    // {
    //     i->render(*this->window);
    // }


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



// void Game::initLevelSettings( int level )
// {
//     /*settings:
//         - # of topSpawner/bot/left/right
//         - speed dla każdego spawnera
//     */
//     srand(time(NULL));

//     switch (level)
//     {
//     case 0: 
//     {
//         randomScale = randomRangefloat(0.7f, 1.5f);
//         randomSpeed = randomRangefloat(400.f, 1000.f);
//         randomDelay = randomRangefloat(0.8f, 2.0f);

//         levelSpawners.push_back( new Spawner( this->window, -90, {0,0}, {randomScale, randomScale}, randomSpeed, randomDelay ) );
//         break;    
//     }
    
//     case 1:
//     {
//         // góra
//         randomScale = randomRangefloat(0.7f, 1.5f);
//         randomSpeed = randomRangefloat(400.f, 1000.f);
//         randomDelay = randomRangefloat(1.2f, 2.0f);
//         levelSpawners.push_back( new Spawner( this->window, -90, {0, 0}, {randomScale, randomScale}, randomSpeed, randomDelay ) );
//         // dół
//         randomScale = randomRangefloat(0.23f, 1.5f);
//         randomSpeed = randomRangefloat(400.f, 1000.f);
//         randomDelay = randomRangefloat(1.2f, 2.0f);
//         levelSpawners.push_back( new Spawner( this->window, 90, {0, SC_HEIGHT-50.0f}, {randomScale, randomScale}, randomSpeed, randomDelay ) );
//         break;
//     }

//     case 2:
//         // góra
//         randomScale = randomRangefloat(2.0f, 3.5f);
//         randomSpeed = randomRangefloat(400.f, 1000.f);
//         randomDelay = randomRangefloat(3.0f, 4.0f);
//         levelSpawners.push_back( new Spawner( this->window, -90, {0, 0}, {randomScale, randomScale}, randomSpeed, randomDelay ) );
//         // dół
//         randomScale = randomRangefloat(2.0f, 2.5f);
//         randomSpeed = randomRangefloat(400.f, 1000.f);
//         randomDelay = randomRangefloat(3.0f, 4.0f);
//         levelSpawners.push_back( new Spawner( this->window, 90, {0, SC_HEIGHT-50.0f}, {randomScale, randomScale}, randomSpeed, randomDelay ) );
//         //dół 2
//         randomScale = randomRangefloat(2.0f, 4.0f);
//         randomSpeed = randomRangefloat(600.f, 1000.f);
//         randomDelay = randomRangefloat(3.0f, 6.0f);
//         levelSpawners.push_back( new Spawner( this->window, 90, {0, SC_HEIGHT-50.0f}, {randomScale, randomScale}, randomSpeed, randomDelay ) );
        
//         break;

//     default:
//         break;
//     }


// }