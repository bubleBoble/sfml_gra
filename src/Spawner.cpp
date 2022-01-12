#include "Spawner.h"

// screen : 1920x1080

Spawner::Spawner(sf::RenderTarget* target, int rotation)
{
    clock = new sf::Clock();
    srand (time(NULL));

    float r = randomRangefloat(20, SC_HEIGHT-20); 

    spawnerPosition = {600, r};

    spawnerShape = new sf::CircleShape(10);
    spawnerShape->setPosition(this->spawnerPosition);

    spawnerShape->setOutlineThickness(3);
    spawnerShape->setOutlineColor(sf::Color::Blue);
    spawnerShape->setFillColor(sf::Color(255, 255, 255, 0));
}

Spawner::~Spawner()
{
    delete spawnerShape;
}


void Spawner::update(sf::Time dt)
{
    // spawn every 3 seconds
    // if (clock->getElapsedTime().asSeconds() > 3){
    //     fireballs.push_back(Fireball( this->spawnerPosition, 50, {0.3, 0.3}, 0 ));
    //     clock->restart();
    // }    

    // if ( fireballs[0].getPosCenter().y > 1000 )
    //     fireballs.erase(fireballs.begin());     // usuwa zawsze pierwszy element bo wszystki maja takie samo v


    // for (auto& i : fireballs)
    //     i.update(dt);
}

void Spawner::render(sf::RenderTarget& target)
{
    target.draw(*spawnerShape);
    // for (auto& i : fireballs)
    //     i.render(target);
}
