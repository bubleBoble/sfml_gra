#include "Player.h"

Player::Player( int _health )
    : health( _health ),
    rightWalk("textures/mage.png", 0, 16, 16, 16),
    leftWalk("textures/mage.png", 64, 16, 16, 16),
    upWalk("textures/mage.png", 64, 0, 16, 16),
    downWalk("textures/mage.png", 0, 0, 16, 16)
{
    speed = 500.f;

    // KONSTRUUUUKTOROINATOR
    // shape.setSize( {50.f, 50.f} );
    // shape.setFillColor( sf::Color::White );
    // shape.setPosition( {
    //     SC_WIDTH/2 - shape.getSize().x/2,
    //     SC_HEIGHT/2 - shape.getSize().y/2
    // });

    this->name = "player 1";

    std::stringstream ss;
    ss << RESOURCE_PATH << "textures/" << "mage.png";
    this->texture.loadFromFile( ss.str() );
    this->sprite = sf::Sprite( texture );
    this->sprite.setTextureRect( {0, 0, 16, 16});
    this->sprite.setScale({6.f, 6.f});

    this->sprite.setPosition(
        SC_WIDTH/2 - shape.getSize().x/2,
        SC_HEIGHT/2 - shape.getSize().y/2
    );
}

Player::~Player()
{

}

void Player::move( sf::Vector2f* dir, sf::Time* dt )
{
    // this->shape.move(
    //     this->speed * *dir * dt->asSeconds()
    // );

    this->sprite.move(
        this->speed * *dir * dt->asSeconds()
    );   
}

void Player::update( sf::Time* dt )
{
    // Update animation
    rightWalk.update( dt->asSeconds(), this->speed );
    leftWalk.update( dt->asSeconds(), this->speed );
    upWalk.update( dt->asSeconds(), this->speed );
    downWalk.update( dt->asSeconds(), this->speed );

    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir.x = 0.f;
        dir.y = -1.f;
        move( &dir, dt );
        upWalk.applyToSprite(this->sprite);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir.x = -1.f;
        dir.y = 0.f;
        move( &dir, dt );
        leftWalk.applyToSprite(this->sprite);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir.x = 0.f;
        dir.y = 1.f;
        move( &dir, dt );
        downWalk.applyToSprite(this->sprite);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir.x = 1.f;
        dir.y = 0.f;
        move( &dir, dt );
        rightWalk.applyToSprite(this->sprite);
    }
}

void Player::render( sf::RenderTarget* target )
{
    // target->draw( this->shape );
    target->draw( this->sprite );

}

sf::Vector2f Player::getPosCenter()
{
    sf::Vector2f pos = this->sprite.getPosition();
    pos.x = pos.x + this->sprite.getGlobalBounds().width / 2;
    pos.y = pos.y + this->sprite.getGlobalBounds().height / 2;
    return pos;

    // this->playerPosCenter = this->shape.getPosition() - sf::Vector2f( this->shape.getPosition().x/2, this->shape.getPosition().y/2 );
    // return this->playerPosCenter;
}