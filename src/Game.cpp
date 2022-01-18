#include "Game.h"

void Game::initWindow() 
{
    this->window = new sf::RenderWindow( sf::VideoMode(SC_WIDTH, SC_HEIGHT), "GNOP", sf::Style::None, settings );
}

Game::Game()
{
    settings.antialiasingLevel = 8;
    initWindow();

    this->window->setFramerateLimit(144);

    this->endGame = false;
    this->stats.health = 10;
    this->stats.points = 0;
    this->mouseHeldDown = false;

    // initialize game objects
    enemies = new Enemy( 100.f, 5 );
    hud = new Hud();
    player = new Player( 10 );
    menu = new Mainmenu( 200.f, 200.f );
    startscreen = new Startscreen( 200.f, 200.f );

    highscoresScreen = false;
    pause = false;
}

Game::~Game()
{
    // delete game objects
    delete this->enemies;
    delete this->hud;
    delete this->player;
    delete this->menu;

    // delte window
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

const bool Game::getEndGame() const
{
    return this->endGame;
}

void Game::update()
{   
    if (!pause)
    {
        if( this->endGame == false )
        {
            updateMousePosition();

            // Updating game objects
            this->enemies->update( 
                &this->stats.health,
                &this->mouseHeldDown,
                &this->stats.points,
                &this->mousePositionView,
                player->getPosCenter() );
                this->updateShooting();
            
            this->hud->update( &this->stats.points, &this->stats.health, player->name );
            this->player->update( &dt );
        }

        if( this->stats.health <= 0 )
        {
            this->endGame = true;
        }
    }
}

void Game::render()
{
    this->window->clear(sf::Color(156, 214, 172, 255));
    this->drawCoordinates( this->window );
    // Render game objects
    this->enemies->render( this->window );
    this->hud->render( this->window );
    this->player->render( this->window );

    for (Bullet& b : bullets)
    {
        this->window->draw(b.shape);
    }

    if(pause)
        this->menu->draw( this->window );

    this->window->display();
}

void Game::run()
{
    while( this->running() )
    {
        pollEvents();
        
        dt = clock.restart();
        
        update();

        render();
    }
}

void Game::pollEvents() 
{   
    while( this->window->pollEvent(this->ev) )
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            // if (this->ev.key.code == sf::Keyboard::Escape)
            //     this->window->close();
            


            // Menu
            if (this->ev.key.code == sf::Keyboard::F2)
            {
                if(pause) { pause = false; }
                else if(!pause) { pause = true; }
            }

            if (pause)
            {
                if (this->ev.key.code == sf::Keyboard::Up)
                    {
                        menu->moveup();
                    }
                if (this->ev.key.code == sf::Keyboard::Down)
                {
                    menu->movedown();
                }

                if (this->ev.key.code == sf::Keyboard::Enter)
                {
                    switch (this->menu->getMMselected())
                    {
                    case 0: // resume
                        pause = false;
                        break;
                    case 1: // new game
                        this->restartGame();
                        break;
                    case 2: // save
                        saveGame();
                        break;
                    case 3: // exit
                        this->window->close();
                        break;
                    case 4: // player1
                        restartGame();
                        player->name = "player 1";
                        stats.plName = player->name;
                        pause = false;
                        break;
                    case 5: // player2
                        restartGame();
                        player->name = "player 2";
                        stats.plName = player->name;
                        pause = false;
                        break;
                    case 6: // player3
                        restartGame();
                        player->name = "player 3";
                        stats.plName = player->name;
                        pause = false;
                        break;

                    default:
                        break;
                    }
                }
            }

        default:
            break;
        }
    }
}

void Game::updateMousePosition()
{
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
} 

void Game::drawCoordinates(sf::RenderTarget* target){
    OxLine = sf::RectangleShape(sf::Vector2f(SC_WIDTH, 2));
    OyLine = sf::RectangleShape(sf::Vector2f(SC_HEIGHT, 2));

    OxLine.setPosition(0, SC_HEIGHT/2);
    OxLine.setFillColor(sf::Color(255, 255, 255, 50));
    OyLine.setPosition(SC_WIDTH/2, 0);
    OyLine.setFillColor(sf::Color(255, 255, 255, 50));
    OyLine.rotate(90);

    target->draw(OxLine);
    target->draw(OyLine);
}

void Game::updateShooting()
{
    aimDir = this->mousePositionView - this->player->getPosCenter();
    aimDirNorm.x = aimDir.x / sqrt( pow(aimDir.x, 2) + pow(aimDir.y, 2) );
    aimDirNorm.y = aimDir.y / sqrt( pow(aimDir.x, 2) + pow(aimDir.y, 2) );
    
    enemiesVec = enemies->getEnemies();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        b1.shape.setPosition(this->player->getPosCenter());
        b1.currVelocity = aimDirNorm * b1.maxSpeed;

        bullets.push_back(Bullet(b1));
    }

    for(size_t i = 0; i<bullets.size(); i++)
    {
        // i.shape.move( sf::Vector2f(i.currVelocity.x*dt.asSeconds(), i.currVelocity.y*dt.asSeconds()) );
        // i.shape.move( i.currVelocity * dt.asSeconds() );
        bullets[i].shape.move( bullets[i].currVelocity );

        // usuwanie
        if (bullets[i].shape.getPosition().x < 0 || 
            bullets[i].shape.getPosition().x > SC_WIDTH ||
            bullets[i].shape.getPosition().y < 0 ||
            bullets[i].shape.getPosition().y > SC_HEIGHT)
        {
            bullets.erase(bullets.begin() + i);
            break;
        } else 
        {
            // kolizja
            for (size_t j = 0; j < enemiesVec.size(); j++)
            {
                if( bullets[i].shape.getGlobalBounds().intersects( enemiesVec[j].getGlobalBounds() ) )
                     bullets.erase(bullets.begin() + i);
                     enemiesVec.erase(enemiesVec.begin() + j);
                     break;
            }
        }
    }
}

void Game::restartGame()
{
    delete this->enemies;
    delete this->hud;
    delete this->player;

    enemies = new Enemy( 100.f, 5 );
    hud = new Hud();
    player = new Player( 10 );

    this->stats.health = 10;
    this->stats.points = 0;

    pause = false;
}

void Game::exitGame()
{
    delete this->enemies;
    delete this->hud;
    delete this->player;
    delete this->menu;
    delete this->window;
}

void Game::saveGame()
{
    FILE *outfile;
    outfile = fopen ("../content/gamedata.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    fwrite (&stats, sizeof(struct Stats), 1, outfile);
    fclose (outfile);
}
