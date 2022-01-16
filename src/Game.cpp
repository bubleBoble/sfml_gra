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
    initLevelSettings( 0 );

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
    
    // top spawners
    for (auto& i : topSpawners)
    {
        random_spawner_time_delay = randomRangefloat(2.0f, 5.0f);

        i->update( dt, this->player->getBox(), 500, {0.23f, 0.23f}, -90, random_spawner_time_delay);        
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



void Game::initLevelSettings( int level )
{
    /*settings:
        - # of topSpawner/bot/left/right
        - speed dla każdego spawnera
        -ruch dla każdego spawnera?
    */
    switch (level)
    {
    case 0: 
    {
        topSpawnerCount = 3;
        botSpawnerCount = 2; 
        leftSpawnerCount = 2;
        rightSpawnerCount = 1;
        
        // top spawners
        sf::Vector2f ran_pos_top { randomRangefloat(0, SC_WIDTH/topSpawnerCount), 0};
        for (int i=0; i<topSpawnerCount; i++)
        {
            float ran_Scale = randomRangefloat(0.23, 0.5);
            sf::Vector2f scale_random {ran_Scale, ran_Scale};
            topSpawners.push_back( new Spawner(this->window, 0, ran_pos_top, scale_random));
            
            ran_pos_top.x = (i+1)*(SC_WIDTH-60)/3 + randomRangefloat(0, SC_WIDTH/topSpawnerCount);
        }
        
        // left spawners
        sf::Vector2f ran_pos_left { randomRangefloat(0, SC_WIDTH/topSpawnerCount), 0};
        for (int i=0; i<topSpawnerCount; i++)
        {
            float ran_Scale = randomRangefloat(0.23, 0.5);
            sf::Vector2f scale_random {ran_Scale, ran_Scale};
            topSpawners.push_back( new Spawner(this->window, 0, ran_pos_top, scale_random));
            
            ran_pos_top.x = (i+1)*(SC_WIDTH-60)/3 + randomRangefloat(0, SC_WIDTH/topSpawnerCount);
        }
        break;    
    }
        
    
    case 1:
        topSpawnerCount = 2;
        botSpawnerCount = 3; 
        leftSpawnerCount = 3;
        rightSpawnerCount = 1;
        break;

    case 2:
        topSpawnerCount = 3;
        botSpawnerCount = 1; 
        leftSpawnerCount = 1;
        rightSpawnerCount = 3;
        break;

    default:
        break;
    }


}