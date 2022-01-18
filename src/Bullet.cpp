#include "Bullet.h"


Bullet::Bullet(  ) 
    : currVelocity(0.f, 0.f), maxSpeed(15.f), radius(5.f)
{
    this->shape.setRadius(this->radius);
    this->shape.setFillColor(sf::Color::Red);
}

Bullet::~Bullet(  )
{
    // log( "bullet destroyed" );
} 

