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
    int collisions{0};
    int life{100};

    /* Game objects
    **************************/
    Player* player;
    Hud* hud;

    Spawner* spawner;
    std::vector<Spawner*> topSpawners;
    std::vector<Spawner*> botSpawners;
    std::vector<Spawner*> leftSpawners;
    std::vector<Spawner*> rightSpawners;

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