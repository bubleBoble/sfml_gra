#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

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

    sf::Clock* clockKolizja;

    void initWindow();

    int level;

    float randomScale;
    float randomSpeed;
    float randomDelay;

    float randomFireballspeed;

    int collisions{0};

    float random_spawner_time_delay {1};

    /* Game objects
    **************************/
    Player* player;
    Hud* hud;

    Spawner* spawner;

    std::vector <Spawner*> levelSpawners;

    /* Game objects methods
    **************************/

public:
    Game();
    ~Game();

    int life{100};


    void run();                 // Main game loop
    void update(sf::Time dt);   
    void render();              
    void pollEvents();

    void drawCoordinates(sf::RenderTarget& target);

    void initLevelSettings( int level );
};