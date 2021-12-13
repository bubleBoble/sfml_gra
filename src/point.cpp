#include "point.h"

// Namespace użyte po to aby skrócic typy zmiennych/metod
// using ... lokalny do namespace'a

namespace point {
    using sf::Vector2f;
    using sf::CircleShape;
    using sf::FloatRect;
    using sf::Time;
    using sf::Color;
    
    /* Constructor / Destructor
    *****************************************/
    Point::Point( const float startX,
                  const float startY,
                  const float radius,
                  const float xvel,
                  const float yvel): 
        m_radius{ radius },
        m_pPos{ startX, startY },
        m_Speed{ 300.0f },
        m_Xvel{ xvel },
        m_Yvel{ yvel }
    {
        this->m_pShape.setRadius( this->m_radius );
        this->m_pShape.setPosition( this->m_pPos );
        this->m_pShape.setFillColor( Color::White );
    }

    Point::~Point(){
        ;
    }
    /* Getters / setters (Accessors)
    *****************************************/
    FloatRect Point::getPos(){
        return this->m_pShape.getGlobalBounds();
    }
    CircleShape Point::getShape(){
        return this->m_pShape;
    }
    float Point::getVelocityX(){
        return this->m_Xvel;
    }
    float Point::getVelocityY(){
        return this->m_Yvel;
    }
    float Point::getRadius(){
        return this->m_radius;
    }
    void Point::setPosX( const float xPos ){
        m_pPos.x = xPos;
    }
    void Point::setPosY( const float yPos ){
        m_pPos.y = yPos;
    }

    /* Collisions
    *****************************************/
    void Point::reboundSide(  ){
        m_Xvel = -m_Xvel;     // Left/right rebound
    }
    void Point::reboundTopBot(  ){
        m_Yvel = -m_Yvel;     // Left/right rebound
    }

    /* Update (dt)
    *****************************************/
    void Point::update( sf::Time& dt ){
        // Update ball position
        m_pPos.x += m_Xvel * m_Speed * dt.asSeconds();
        m_pPos.y += m_Yvel * m_Speed * dt.asSeconds();

        // Move the point
        m_pShape.setPosition(m_pPos);
    }

}
