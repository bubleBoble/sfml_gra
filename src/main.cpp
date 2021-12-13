#include "config.h"
#include "point.h"
#include <sstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define log(x) std::cout << x << std::endl;                                                                     // Makro pomocnicze (można to zrobić w lepszy sposób)

#define randomRangeInt(l, h) (rand() % (h - l + 1) + l)                                                         // Makro użyte do losowego generowania wielkości i prędkości              
#define randomRangefloat(l, h) (l + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(h-l))))     // kulek

int main() {

    // Radnom seed init
    srand(time(0));

    // Create window
    sf::VideoMode vm(SC_WIDTH, SC_HEIGHT);
    sf::RenderWindow window(vm, "GNOP", sf::Style::Titlebar | sf::Style::Close);
    sf::View view(sf::FloatRect(0, 0, 800.f, 600.f));

    // load font
    sf::Font font;
    std::string source_dir = RESOURCE_PATH; 

    if (!font.loadFromFile(source_dir + "sansation.ttf"))
        return EXIT_FAILURE;

    // Load backgroud texture
    sf::Texture texture;
    if (!texture.loadFromFile(source_dir + "background2.jpg"))
        return EXIT_FAILURE;
    
    // Load backgroud sprite
    sf::Sprite BackgroundSprite;
    BackgroundSprite.setTexture(texture);
    BackgroundSprite.setPosition(0.f, 0.f);
    unsigned int c = 212;
    BackgroundSprite.setColor(sf::Color(c,c,c,255));

    // Init Hub variables
    int score = 0;
    int lives = 3;

    // Create a text object
    sf::Text hud;
    hud.setFont(font);
    hud.setCharacterSize(24);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(10.f, 10.f);

    // Point object
    // point::Point ball(SC_WIDTH/2, SC_HEIGHT/2, POINT_RADIUS);

    // making vector of point objects
    std::vector<point::Point> points;

    // małe punkty mają być większe.

    for(int i = 0; i<1; i++){
        int rand_radius = randomRangefloat(15, 20);
        float rand_speed_X = randomRangefloat(-4, 4);
        float rand_speed_Y = randomRangefloat(-4, 4);
        point::Point pt(SC_WIDTH/2, SC_HEIGHT/2, rand_radius, rand_speed_X, rand_speed_Y);
        points.push_back(pt);
        log(rand_radius);
    }

    // Clock for timing everything
    sf::Clock clock;

    while (window.isOpen()) {
        /* Handle the player input 
         *****************************************/
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                // Escape
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                
                // Left arrow
                if (event.key.code == sf::Keyboard::Left)
                    ;

                // Right arrow
                if (event.key.code == sf::Keyboard::Right)
                    ; 
            }
            
            if (event.type == sf::Event::KeyReleased) 
            {
                // Left arrow
                if (event.key.code == sf::Keyboard::Left)
                    ;

                // Right arrow
                if (event.key.code == sf::Keyboard::Right)
                    ;
            }
        }
        /*
         * Update
         *****************************************/
        // Update delta time
        sf::Time dt = clock.restart();

        // Handle ball hiting the bottom etc. logika jak zmiana kierunku ruchu itd.
        // many balls
        for (point::Point& p: points) {
            p.update(dt);
            sf::FloatRect ballPos = p.getPos();
        
            if ( ((p.getPos().left+2*p.getRadius()) > SC_WIDTH) || (p.getPos().left < 0) ) {
                p.reboundSide(); 
            } else if ( ((p.getPos().top+2*p.getRadius()) > SC_HEIGHT) || (p.getPos().top < 0) ) {
                p.reboundTopBot();
        }
        }

        // // one ball
        // ball.update(dt);

        // sf::FloatRect ballPos = ball.getPos();
        
        // if ( ((ball.getPos().left+2*POINT_RADIUS) > SC_WIDTH) || (ball.getPos().left < 0) ) {
        //      ball.reboundSide(); 
        // } else if ( ((ball.getPos().top+2*POINT_RADIUS) > SC_HEIGHT) || (ball.getPos().top < 0) ) {
        //     ball.reboundTopBot();
        // }
        

        // Update HUD
        std::stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;
        hud.setString(ss.str());


        /*
         * Draw
         ****************************************/
        window.clear();
        window.draw(BackgroundSprite);
        window.draw(hud);
        // window.draw(ball.getShape());
        for (point::Point& p: points){
            window.draw(p.getShape());
        }
        window.display();
    }

    return 0;
}