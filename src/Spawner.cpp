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
    // spawn every 3 seconds
    // log(clock->getElapsedTime().asSeconds());
    if (clock->getElapsedTime().asSeconds() > 0.5)
    {
        // log(clock->getElapsedTime().asSeconds());
        // log("tutaj create fireball");
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

    // for (auto& i : fireballs)
    // {
    //     if ( i->getPosition().y > 600 )
    //     {
    //         fireballs.erase();
    //     }
    // }

    // if ( fireballs[0]->getPosCenter().y > 1000 )
    // {
    //     log("erase");
    //     // log(fireballs[0]->getPosCenter().y);
    //     // fireballs.erase(fireballs.begin());     // usuwa zawsze pierwszy element bo wszystkie maja takie samo v
    // }

    for (auto& i : fireballs)
        i->update(dt);
}

void Spawner::render(sf::RenderTarget& target)
{
    target.draw(*spawnerShape);
    for (auto& i : fireballs)
        i->render(target);
}
