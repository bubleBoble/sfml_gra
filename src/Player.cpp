#include "Player.h"

// Constructor
Player::Player( const sf::Vector2f pos, float speed, sf::Vector2f scale )
: 
    rightWalk("textures/mage.png", 0, 16, 16, 16),
    leftWalk("textures/mage.png", 64, 16, 16, 16),
    upWalk("textures/mage.png", 64, 0, 16, 16),
    downWalk("textures/mage.png", 0, 0, 16, 16)
{
    setSpriteScale(scale.x, scale.y);
    setSpritePos( pos );
    setSpriteSpeed( speed );

    std::string texPath = RESOURCE_PATH;
    texPath += "textures/mage.png";
    frontTex.loadFromFile(texPath, sf::IntRect(0, 0, 16, 16));
    this->sprite.setTexture(frontTex);

    setEntityBox( {0.5, 0.7} );
}

void Player::updateKeyboard(sf::Time dt)
{
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir = {0.0f, -1.0f};
        move_(dir.x, dir.y, dt);
        upWalk.applyToSprite(this->sprite);
        // dir = {0.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir = {-1.f, 0.f};
        move_(dir.x, dir.y, dt);
        leftWalk.applyToSprite(this->sprite);
        // dir = {0.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir = {0.f, 1.f};
        move_(dir.x, dir.y , dt);
        downWalk.applyToSprite(this->sprite);
        // dir = {0.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = {1.f, 0.f};
        move_(dir.x, dir.y, dt);
        rightWalk.applyToSprite(this->sprite);
        // dir = {0.f, 0.f};
    } 
    dir = {0.f, 0.f};
}

void Player::update( sf::Time dt )
{
    rightWalk.update( dt.asSeconds(), this->m_speed );
    leftWalk.update( dt.asSeconds(), this->m_speed );
    upWalk.update( dt.asSeconds(), this->m_speed );
    downWalk.update( dt.asSeconds(), this->m_speed );
}
