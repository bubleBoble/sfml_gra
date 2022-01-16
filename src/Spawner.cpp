#include "Spawner.h"

// screen : 1920x1080

Spawner::Spawner(sf::RenderTarget* target, float rotation, sf::Vector2f pos, sf::Vector2f _fbscale)
{
    clock = new sf::Clock();

    fbScale = _fbscale;
    spawnerPosition = pos;

    spawnerShape = new sf::CircleShape(10);
    spawnerShape->setPosition(this->spawnerPosition);

    spawnerShape->setOutlineThickness(3);
    spawnerShape->setOutlineColor(sf::Color::Blue);
    spawnerShape->setFillColor(sf::Color(255, 255, 255, 0));


}

Spawner::~Spawner()
{
    delete spawnerShape;

    for( auto& i : fireballs )
        delete i;
}


void Spawner::update(sf::Time dt, sf::FloatRect player, float speed, sf::Vector2f scale, float rotation, float _delay)
{
    if (clock->getElapsedTime().asSeconds() > _delay)
    {
        fireballs.push_back( new Fireball( this->spawnerPosition, speed, this->fbScale, rotation ));
        clock->restart();
    }    


    for (int i=0; i<fireballs.size(); i++)
    {
        if ((fireballs[i]->getPosition().y > SC_HEIGHT) |
            (checkCollisionPlayer( player )))
        {
            delete fireballs[i];
            fireballs.erase( fireballs.begin()+i );
        }
    }

    for (auto& i : fireballs)
        i->update(dt);
}

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
