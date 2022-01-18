#include "Spawner.h"

// screen : 1920x1080

Spawner::Spawner(sf::RenderTarget* target, float rotation, sf::Vector2f pos, sf::Vector2f _fbscale, float _speed, float _delay)
{
    timeDelay = _delay;
    clockFbDelay = new sf::Clock();

    spawnerSpeed = _speed;
    fbScale = _fbscale;
    spawnerPosition = pos;

    spawnerShape = new sf::CircleShape(10);
    spawnerShape->setPosition(this->spawnerPosition);

    spawnerShape->setOutlineThickness(3);
    spawnerShape->setOutlineColor(sf::Color::Blue);
    spawnerShape->setFillColor(sf::Color(255, 255, 255, 0));

    spawnerRotation = rotation;

    dir = {0.0f, 1.0f};
}

Spawner::~Spawner()
{
    delete spawnerShape;
    delete clockFbDelay;

    for( auto& i : fireballs )
        delete i;
}

void Spawner::update(sf::Time dt, Player& player, float speed, sf::Vector2f scale, float rotation, float _delay)
{
    // updateKeyboard(dt);
    // Nie potrzebne parametry:
    // speed w update to fireball speed
    //scale nie potrzebne tutaj
    // rotatin nie potrzebne tutaj
    // _delay nie potrzebne tutaj

    if (clockFbDelay->getElapsedTime().asSeconds() > timeDelay)
    {
        fireballs.push_back( new Fireball( this->spawnerPosition, speed, this->fbScale, spawnerRotation ));
        clockFbDelay->restart();
    }   



    for (int i=0; i<fireballs.size(); i++)
    {
        if ((fireballs[i]->getPosition().y > SC_HEIGHT) |
            (checkCollisionPlayer( player.getBox() )))
        {
            delete fireballs[i];
            fireballs.erase( fireballs.begin()+i );
            player.life --;
        }
    }

    for (auto& i : fireballs)
        i->update(dt);


    // moveLeftRight(dt);
    moveUpDown(dt);
}

// void Spawner::update(sf::Time dt, sf::FloatRect player, float speed, sf::Vector2f scale, float rotation, float _delay)
// {
//     // updateKeyboard(dt);
//     // Nie potrzebne parametry:
//     // speed w update to fireball speed
//     //scale nie potrzebne tutaj
//     // rotatin nie potrzebne tutaj
//     // _delay nie potrzebne tutaj

//     if (clockFbDelay->getElapsedTime().asSeconds() > timeDelay)
//     {
//         fireballs.push_back( new Fireball( this->spawnerPosition, speed, this->fbScale, spawnerRotation ));
//         clockFbDelay->restart();
//     }    


//     for (int i=0; i<fireballs.size(); i++)
//     {
//         if ((fireballs[i]->getPosition().y > SC_HEIGHT) |
//             (checkCollisionPlayer( player )))
//         {
//             delete fireballs[i];
//             fireballs.erase( fireballs.begin()+i );
//         }
//     }

//     for (auto& i : fireballs)
//         i->update(dt);


//     moveLeftRight(dt);

// }

void Spawner::render(sf::RenderTarget& target)
{
    target.draw(*spawnerShape);
    for (auto& i : fireballs)
        i->render(target);
}


void Spawner::setTimeDelay( float _timeDelay )
{
    this->timeDelay = _timeDelay;
}

bool Spawner::checkCollisionPlayer( sf::FloatRect player ) 
{
    for (auto& i : fireballs)
    {
        if ( i->getBox().intersects(player) )
        {
            return true;
        }else {
            return false;
        }
    }
}

void Spawner::move(const float dirX, const float dirY, sf::Time dt)
{
    this->spawnerPosition.x += spawnerSpeed * dirX * dt.asSeconds();
    this->spawnerPosition.y += spawnerSpeed * dirY * dt.asSeconds();
    this->spawnerShape->setPosition(spawnerPosition);
}

void Spawner::moveLeftRight(sf::Time dt)
{
    if ( spawnerPosition.x >= SC_WIDTH) { dir = {-1.f, 0.f}; }
    else if ( spawnerPosition.x <= 0 ) { dir = {1.f, 0.f}; }
    move (dir.x, dir.y, dt);
}

void Spawner::moveUpDown(sf::Time dt)
{
    if ( spawnerPosition.y >= SC_HEIGHT) { dir = {0.f, -1.f}; }
    else if ( spawnerPosition.x <= 0 ) { dir = {0.f, 1.f}; }
    move (dir.x, dir.y, dt);
}

// void Spawner::updateKeyboard(sf::Time dt)
// {
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//     {
//         this->dir = {0.0f, -1.0f};
//         this->move(dir.x, dir.y, dt);
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//     {
//         this->dir = {-1.f, 0.f};
//         this->move(dir.x, dir.y, dt);
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//     {
//         this->dir = {0.f, 1.f};
//         this->move(dir.x, dir.y , dt);
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//     {
//         this->dir = {1.f, 0.f};
//         this->move(dir.x, dir.y, dt);
//     } 

//     this->dir = {0.f, 0.f};
// }