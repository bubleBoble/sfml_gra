#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

class FireballAnimation {
public:
    FireballAnimation() { ; }
    FireballAnimation (std::string texName)
    :
        holdTime(0.0005f)
    { 
        std::string texPath = RESOURCE_PATH;
        frames[0].loadFromFile(texPath + "textures/red/keyframes/1.png");
        frames[1].loadFromFile(texPath + "textures/red/keyframes/2.png");
        frames[2].loadFromFile(texPath + "textures/red/keyframes/3.png");
        frames[3].loadFromFile(texPath + "textures/red/keyframes/4.png");
        frames[4].loadFromFile(texPath + "textures/red/keyframes/5.png");
        frames[5].loadFromFile(texPath + "textures/red/keyframes/6.png");
    }
    void applyToSprite( sf::Sprite& s ) const {
        s.setTexture(frames[iFrame]);
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
    static constexpr int nFrames = 6;
    float holdTime;
    sf::Texture texture;
    sf::Texture frames[nFrames];
    int iFrame = 0;
    float time = 0.0f;
};