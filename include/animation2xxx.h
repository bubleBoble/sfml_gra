#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

class Animation {
public:
    Animation() { ; }
    Animation (std::string texName, int x, int y, int width, int height)
    :
        holdTime(0.01f)
    {
        std::string texPath = RESOURCE_PATH;
        texPath += texName;
        texture.loadFromFile( texPath );
        for (int i = 0; i < nFrames; i++) {
            frames[i] = { x+ i *width, y, width, height  };
        }
    }
    void applyToSprite( sf::Sprite& s ) const {
        s.setTexture(texture);
        s.setTextureRect( frames[iFrame] );
    }
    void update(float dt, float playerSpeed) {
        holdTime = playerSpeed*0.0001;
        time += dt;
        while (time >= holdTime) {
            time -= holdTime;
            advance();
        }
    }

private:
    void advance(){
        if (++iFrame >= nFrames) {
            iFrame = 0;   
        }
    }
    static constexpr int nFrames = 4;
    float holdTime;
    sf::Texture texture;
    sf::IntRect frames[nFrames];
    int iFrame = 0;
    float time = 0.0f;
};