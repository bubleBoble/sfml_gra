#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <Game.h>
#include <iostream>
#include <ctime>
#include <sstream>
 
#include "config.h"
#include "Enemy.h"
#include "Hud.h"
#include "Player.h"
#include "Bullet.h"
#include "Mainmenu.h"
#include "StartScreen.h"

class Game
{
private:
    void initWindow();

    // Window
    sf::ContextSettings settings;
    sf::RenderWindow* window;
    sf::Event ev;

    // Coordinates
    sf::RectangleShape OxLine;
    sf::RectangleShape OyLine;

    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;

    // Logic
    bool highscoresScreen;
    bool endGame;
    bool pause;
    bool mouseHeldDown;

    struct Stats {
        std::string plName;
        int health;
        int points;
    };

    Stats stats; 

    sf::Clock clock;
    sf::Time dt;

    // Game objects
    Enemy* enemies;
    std::vector<sf::CircleShape> enemiesVec;
    Hud* hud;
    Player* player;
    Mainmenu* menu;
    Startscreen* startscreen;

    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    Bullet b1;
    std::vector<Bullet> bullets;

    void pollEvents();
    void drawCoordinates(sf::RenderTarget* target);
    
    void updateShooting();

    void updateMousePosition(); 

    void restartGame();
    void exitGame();
    void saveGame();

    void write(const std::string& file_name, Stats& data);
    void read(const std::string& file_name, Stats& data);

public:
    Game();
    ~Game();

    const bool running() const;
    const bool getEndGame() const;

    void update();   
    void render();       
    void run();       
};