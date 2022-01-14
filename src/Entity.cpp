#include "Entity.h"


/* Constructor & destructor
********************************/
void Entity::init( sf::Vector2f _pos, sf::Vector2f _scale, float _speed ) 
{   
    setSprite("mage.png", 0, 16, 16, 16);
    setSpriteScale(6, 6);
    setSpritePos({SC_WIDTH/2 - getSpriteSize().x, SC_HEIGHT/2 - getSpriteSize().y });
    setSpriteSpeed(_speed);
}

// Constructor 1
Entity::Entity( sf::Vector2f entityPos, sf::Vector2f entityScale, float entitySpeed)
{
    init(entityPos, entityScale, entitySpeed);
}

// Constructor 2
Entity::Entity()
{
    ;
}

// Destructor
Entity::~Entity()
{
    ;
}

/* Getters & setters
********************************/
// Getter pos center
sf::Vector2f Entity::getPosCenter() 
{
    sf::Vector2f pos = this->sprite.getPosition();
    pos.x = pos.x + this->sprite.getGlobalBounds().width / 2;
    pos.y = pos.y + this->sprite.getGlobalBounds().height / 2;
    return pos;
}

// Getter size
sf::Vector2f Entity::getSpriteSize() 
{
    sf::Vector2f size;
    size.x = this->sprite.getGlobalBounds().width;
    size.y = this->sprite.getGlobalBounds().height;
    return size;
}

// Setter sprite
void Entity::setSprite(std::string textureName, int tex_x, int tex_y, int tex_width, int tex_height)
{
    std::string tex_path = RESOURCE_PATH;
    tex_path += "textures/";
    tex_path += textureName;
    this->texture.loadFromFile(tex_path);
    this->sprite = sf::Sprite(texture);
    this->sprite.setTextureRect( {tex_x, tex_y, tex_width, tex_height});
}

// Setter scale
void Entity::setSpriteScale(float scale_x, float scale_y)
{
    this->sprite.setScale(scale_x, scale_y);
}

// Setter speed
void Entity::setSpriteSpeed(float speed)
{
    this->m_speed = speed;
}

// Setter pos
void Entity::setSpritePos(sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

// set box
void Entity::setEntityBox(sf::Vector2f scale) 
{
    entityBox = sf::RectangleShape( getSpriteSize() );
    entityBox.setScale(scale);
    entityBox.setPosition( 
        this->sprite.getPosition().x - (entityBox.getSize().x * scale.x - getSpriteSize().x) / 2.f,
        this->sprite.getPosition().y - (entityBox.getSize().y * scale.y - getSpriteSize().y) / 2.f
        );
    entityBox.setOutlineThickness(3);
    
    entityBox.setOutlineColor(sf::Color::Red);
    entityBox.setFillColor(sf::Color(255, 255, 255, 0));
};


// move box
void Entity::moveEntityBox( sf::Vector2f move )
{
    this->entityBox.setPosition(move);
}


// set circle
void Entity::setEntityCircle(sf::Vector2f scale) 
{
    this->entityCircle = sf::CircleShape( 15 );
    this->entityCircle.setPosition(
        this->sprite.getPosition().x,
        this->sprite.getPosition().y
    );
    this->entityCircle.setOutlineThickness(3);
    this->entityCircle.setScale(scale);
    this->entityCircle.setOutlineColor(sf::Color::Red);
    this->entityCircle.setFillColor(sf::Color(255, 255, 255, 0));    
}

// Set circle pos
void Entity::moveEntityCircle(sf::Vector2f pos) 
{
    this->entityCircle.move( {pos} );
}

/* Render & update
********************************/

// Render
void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
    target.draw(this->entityBox);
    target.draw(this->entityCircle);
}

// move
void Entity::move_(const float dirX, const float dirY, sf::Time dt)
{   
    this->entityCircle.move(
        this->m_speed * dirX * dt.asSeconds(),
        this->m_speed * dirY * dt.asSeconds()
    );   

    this->entityBox.move(
        this->m_speed * dirX * dt.asSeconds(),
        this->m_speed * dirY * dt.asSeconds()
    );

    this->sprite.move(
        this->m_speed * dirX * dt.asSeconds(),
        this->m_speed * dirY * dt.asSeconds()
        );
}

sf::FloatRect Entity::getBox()
{
    return this->entityBox.getGlobalBounds();
}


// Read keyboard => move
// void Entity::updateKeyboard(sf::Time dt)
// {
//     // Move player
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//         move_(0.f, -1.f, dt);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//         move_(-1.f, 0.f, dt);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//         move_(0.f, 1.f, dt);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//         move_(1.f, 0.f, dt);
// }



