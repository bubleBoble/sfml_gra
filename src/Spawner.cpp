#include "Spawner.h"

// screen : 1920x1080

Spawner::Spawner(sf::RenderTarget* target, int rotation, sf::Vector2f pos)
{
    clock = new sf::Clock();

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


void Spawner::update(sf::Time dt)
{
    if (clock->getElapsedTime().asSeconds() > this->timeDelay)
    {
        fireballs.push_back( new Fireball( this->spawnerPosition, 500, {0.3, 0.3}, -90 ));
        clock->restart();
    }    


    for (int i=0; i<fireballs.size(); i++)
    {
        if (fireballs[i]->getPosition().y > 600)
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
