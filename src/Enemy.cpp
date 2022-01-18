#include "Enemy.h"


Enemy::Enemy( float _enemySpawnTimerMax, int _maxEnemies)
{
    /*  
        Specify # of enemies
    */

    this->enemySpawnTimerMax = _enemySpawnTimerMax;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = _maxEnemies;

    this->shape.setRadius( 50.f );
    this->shape.setFillColor(sf::Color::Cyan);
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(4.f);
    this->shape.setPointCount( 20 );
}

Enemy::~Enemy()
{
    ;
}

void Enemy::initEnemies()
{   
    /*
        makes vector of random enemies
    */

    this->shape.setPosition(
        randomRangefloat( 0.f, SC_WIDTH-this->shape.getRadius() ),
        0.f         
    );

    int type = rand() % 5;

    switch (type)
    {
    case 0:
        this->shape.setScale({0.8f, 0.8f});
        this->shape.setFillColor(sf::Color::Blue);
        break;
    case 1:
        this->shape.setScale({0.2f, 0.2f});
        this->shape.setFillColor(sf::Color::Red);
        break;
    case 2:
        this->shape.setScale({0.5f, 0.5f});
        this->shape.setFillColor(sf::Color::Green);
        break;
    case 3:
        this->shape.setScale({0.35f, 0.35f});
        this->shape.setFillColor(sf::Color::Yellow);
        break;
    case 4:
        this->shape.setScale({2.f, 2.f});
        this->shape.setFillColor(sf::Color::Magenta);
        break;
    
    default:
        break;
    }

    // this->enemy.setFillColor(sf::Color::Magenta);
    this->enemies.push_back(this->shape);
}

void Enemy::update( int* health, bool* mouseHeldDown, int* points, sf::Vector2f* mousePositionView, sf::Vector2f playerPosCenter )
{

    // Spawn enemies
    if(this->enemies.size() <= maxEnemies)
    {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->initEnemies();
            this->enemySpawnTimer = 0.f; 
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    // Move enemies
    for(int i=0; i < this->enemies.size(); i++)
    {
        // Normalized dir vector towards the player
        dir = playerPosCenter - enemies[i].getPosition();
        dir.x = dir.x / ( sqrt(pow(dir.x, 2) + pow(dir.y, 2)) );
        dir.y = dir.y / sqrt( pow(dir.x, 2) + pow(dir.y, 2) );
        // log (dir.x << " " << dir. y);

        this->enemies[i].move( dir );

        if( this->enemies[i].getGlobalBounds().contains(playerPosCenter) )
        {
            this->enemies.erase(this->enemies.begin() + i);
            *health -= 1.f;
        }
    }

    // check if emeny was clicked
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if( !*mouseHeldDown ) 
        {
            *mouseHeldDown = true;
            bool deleted = false;
            for(size_t i=0; i<this->enemies.size() && deleted == false; i++)
            {
                if( this->enemies[i].getGlobalBounds().contains(*mousePositionView) )
                {
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);
                    *points += 1.f;
                }
            }
        }
    }
    else
    {
        *mouseHeldDown = false;
    }
}

void Enemy::render( sf::RenderTarget* target )
{
    for( auto& e : this->enemies )
    {
        target->draw(e);
    }
}

std::vector <sf::CircleShape> Enemy::getEnemies()
{
    return enemies;
}












