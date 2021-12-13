#pragma once
#include "config.h"
#include <SFML/Graphics.hpp>

namespace point{
    class Point{
    private:
        sf::Vector2f        m_pPos;    // point position
        sf::CircleShape     m_pShape;  // point shape/sprite

        float m_Speed;               // Pixels/sec
        float m_Xvel;                // Horizontal vel.
        float m_Yvel;                // Vertical vel.
        float m_radius;              // Point radius
        
        static constexpr float RADIUS{ POINT_RADIUS };   // constexpr bo const nie można było zainicjować

    public:
        /* Constructor / Destructor
        *****************************************/
        Point( const float startX, const float startY, const float radius, const float xvel, const float yvel );
        ~Point();

        /* Getters / setters (Accessors)
        *****************************************/
        sf::FloatRect       getPos();         // float rect => (x_pos, y_pos, width, height)
        sf::CircleShape     getShape();
        float               getVelocityX();
        float               getVelocityY();
        float               getRadius();

        void setPosX( const float xPos );
        void setPosY( const float yPos );
        void setColor( const int[4] );

        /* Collisions
        *****************************************/
        // stb == 0 => hit sides
        // std == 1 => hit top/bot
        void reboundSide(  );     
        void reboundTopBot(  );     

        /* Update (dt)
        *****************************************/
        void update( sf::Time& dt );
    };
}