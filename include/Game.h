#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Hud.h"
#include "FireBall.h"
#include "Spawner.h"

class Game
{
private:
    sf::RenderWindow* window;
    sf::Clock clock;
    sf::Time dt;
    sf::Event ev;
    sf::ContextSettings settings;

    sf::RectangleShape OxLine;
    sf::RectangleShape OyLine;

    void initWindow();

    /* Game objects
    **************************/
    Player* player;
    Hud* hud;

    Fireball* RL_fireball;
    Fireball* LR_fireball;
    Fireball* UD_fireball;
    Fireball* DU_fireball;

    Spawner* spawner;

    /* Game objects methods
    **************************/


public:
    Game();
    ~Game();

    void run();                 // Main game loop
    void update(sf::Time dt);   
    void render();              
    void pollEvents();

    void drawCoordinates(sf::RenderTarget& target);
};