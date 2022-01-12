#include "Fireball.h"

// Constructor
Fireball::Fireball()
{
    ;
}

Fireball::Fireball( const sf::Vector2f pos, float speed, sf::Vector2f scale, float rotation)
:
    fireballLeft("blabla")
    // fireballRight("blabla"),
    // fireballUp("blabla"),
    // fireballDown("blabla")
{
    log("fireball created");
    setSpriteScale(scale.x, scale.y);
    setSpritePos( pos );
    setSpriteSpeed( speed );

    std::string texPath = RESOURCE_PATH;
    texPath += "textures/red/keyframes/1.png";
    startTex.loadFromFile(texPath);
    this->sprite.setTexture(startTex);

    setEntityBox( {1, 1} );
    moveEntityBox(sprite.getPosition());
    setEntityCircle( fCirc_scale );

    rotateFireball(rotation);

    entityCircle.setRotation(rotation);
    entityBox.setRotation(rotation);

    if ( rotation == 0 )
    {
        entityCircle.move({0, 197*scale.x / 2.3f});
        dir = {-1.0f, 0.0f};
    }
    else if (rotation == 180)
    {
        entityCircle.move({0, -197*scale.x / 2.3f});
        dir = {1.0f, 0.0f};
    }
    else if (rotation == 90)
    {
        entityCircle.move({-197*scale.x / 2.3f, 0});
        dir = {0.0f, -1.0f};
    }
    else if (rotation == -90)
    {
        entityCircle.move({197*scale.x / 2.3f, 0});
        dir = {0.0f, 1.0f};
    } 
}

Fireball::~Fireball()
{
    log("fireball destroyed");
}

void Fireball::update( sf::Time dt )
{
    fireballLeft.update( dt.asSeconds(), this->m_speed );
    // fireballRight.update( dt.asSeconds(), this->m_speed );
    // fireballUp.update( dt.asSeconds(), this->m_speed );
    // fireballDown.update( dt.asSeconds(), this->m_speed );

    move_(dir.x, dir.y, dt);

    fireballLeft.applyToSprite(this->sprite);

    // this->entityBox.setRotation( this->getFireballRotation() );
    // this->entityCircle.setRotation( this->getFireballRotation() );
}

void Fireball::rotateFireball( float angle )
{
    this->sprite.setRotation(angle);
}

float Fireball::getFireballRotation()
{   
    return this->sprite.getRotation();
}

sf::Vector2f Fireball::getPosition()
{
    return this->sprite.getPosition();
}


// // ZAMIAST TEGO CIĄGŁY RUCH
// void Fireball::updateKeyboard(sf::Time dt)
// {
//     // Move player
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//     {
//         dir = {0.0f, -1.0f};
//         move_(dir.x, dir.y, dt);
//         fireballUp.applyToSprite(this->sprite);
//         if(this->sprite.getRotation() != 90) 
//             rotateFireball(90);
//             entityCircle.setRotation(90);
//             entityBox.setRotation(90);
//         // dir = {0.f, 0.f};
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//     {
//         dir = {-1.f, 0.f};
//         move_(dir.x, dir.y, dt);
//         fireballLeft.applyToSprite(this->sprite);
//         if(this->sprite.getRotation() != 0) 
//             rotateFireball(0);
//             entityCircle.setRotation(0);
//             entityBox.setRotation(0);
//         // dir = {0.f, 0.f};
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//     {
//         dir = {0.f, 1.f};
//         move_(dir.x, dir.y , dt);
//         fireballDown.applyToSprite(this->sprite);
//         if(this->sprite.getRotation() != -90) 
//             rotateFireball(-90);
//             entityCircle.setRotation(-90);
//             entityBox.setRotation(-90);
//         // dir = {0.f, 0.f};
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//     {
//         dir = {1.f, 0.f};
//         move_(dir.x, dir.y, dt);
//         fireballRight.applyToSprite(this->sprite);
//         if(this->getFireballRotation() != 180) 
//             rotateFireball(180);
//             entityCircle.setRotation(180);
//             entityBox.setRotation(180);
//         // dir = {0.f, 0.f};
//     } 
//     dir = {0.f, 0.f};
// }
