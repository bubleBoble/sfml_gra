#include "config.h"
#include <sstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {

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

    
    int score = 0;
    int lives = 3;

    // Create a text object
    sf::Text hud;
    hud.setFont(font);
    hud.setCharacterSize(24);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(10.f, 10.f);

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
        ;
        ;

        // Update HUD
        std::stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;
        hud.setString(ss.str());


        /*
         * Draw
         ****************************************/
        window.clear();
        window.draw(hud);
        window.draw(BackgroundSprite);
        window.display();
    }

    return 0;
}