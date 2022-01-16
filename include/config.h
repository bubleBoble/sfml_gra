#pragma once
#include <cmath>

#define RESOURCE_PATH "../content/"     // Path relative to .exe file (bin foler)

#define SC_WIDTH sf::VideoMode::getDesktopMode().width
#define SC_HEIGHT sf::VideoMode::getDesktopMode().height

// #define SC_WIDTH 800
// #define SC_HEIGHT 700


#define WINDOW_WIDTH 1450.0f
#define WINDOW_HEIGHT 800.0f

#define VIEW_WIDTH 500.f
#define VIEW_HEIGHT 500.f

#define TEST_POINT_RADIUS 70.0f
#define TEST_ENTITY_SIZE 30.0f

// help makros
#define log(x) std::cout << x << std::endl;                                                                     // Makro pomocnicze (można to zrobić w lepszy sposób)

#define randomRangeInt(l, h) (rand() % (h - l + 1) + l)                                                         // Makro użyte do losowego generowania wielkości i prędkości              
#define randomRangefloat(l, h) (l + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(h-l))))     // kulek

#define randomRGB {randomRangeInt(0, 255), randomRangeInt(0, 255), randomRangeInt(0, 255), 255}                // Alfa zawsze 255

// sf::Style::Close | sf::Style::Titlebar