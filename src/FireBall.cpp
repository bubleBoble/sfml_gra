#include "Fireball.h"

// Constructor
Fireball::Fireball( const sf::Vector2f pos, float speed, sf::Vector2f scale )
:
    fireballLeft("blabla"),
    fireballRight("blabla"),
    fireballUp("blabla"),
    fireballDown("blabla")
{
    setSpriteScale(scale.x, scale.y);
    setSpritePos( pos );
    setSpriteSpeed( speed );

    setEntityBox( {2, 2} );
}

void Fireball::updateKeyboard(sf::Time dt)
{
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        dir = {0.0f, -1.0f};
        move_(dir.x, dir.y, dt);
        fireballUp.applyToSprite(this->sprite);
        if(this->sprite.getRotation() != 90) 
            rotateFireball(90);
        // dir = {0.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        dir = {-1.f, 0.f};
        move_(dir.x, dir.y, dt);
        fireballLeft.applyToSprite(this->sprite);
        if(this->sprite.getRotation() != 0) 
            rotateFireball(0);
        // dir = {0.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        dir = {0.f, 1.f};
        move_(dir.x, dir.y , dt);
        fireballDown.applyToSprite(this->sprite);
        if(this->sprite.getRotation() != -90) 
            rotateFireball(-90);
        // dir = {0.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        dir = {1.f, 0.f};
        move_(dir.x, dir.y, dt);
        fireballRight.applyToSprite(this->sprite);
        if(this->sprite.getRotation() != 180) 
            rotateFireball(180);
        // dir = {0.f, 0.f};
    } 
    dir = {0.f, 0.f};
}

void Fireball::update( sf::Time dt )
{
    fireballLeft.update( dt.asSeconds(), this->m_speed );
    fireballRight.update( dt.asSeconds(), this->m_speed );
    fireballUp.update( dt.asSeconds(), this->m_speed );
    fireballDown.update( dt.asSeconds(), this->m_speed );
}

void Fireball::rotateFireball( float angle )
{
    this->sprite.setRotation(angle);
}
