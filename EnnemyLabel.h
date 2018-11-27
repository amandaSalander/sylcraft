//
// Created by amanda on 24/11/18.
//

#ifndef PROJECT_1_ENNEMYLABEL_H
#define PROJECT_1_ENNEMYLABEL_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Position.h"
#include <iostream>
#include "TextTexture.h"

class EnnemyLabel {
private:
    int attackPower;
    int defensePower;
    int maxStamina;
    int stamina;
    bool attacked;
    bool attaking;
public:
    EnnemyLabel(const int &_attackPower, const int &_defensePower, const int &_stamina, const int &_maxStamina,
            bool _attacked=false,bool _attaking=false):
    attackPower(_attackPower),defensePower(_defensePower),maxStamina(_maxStamina),
    stamina(_stamina),attacked(_attacked),attaking(_attaking){};
    void render(const Position &position,SDL_Renderer *gRenderer);

    void setAttacked(bool attacked);
};


#endif //PROJECT_1_ENNEMYLABEL_H
