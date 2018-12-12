//
// Created by amanda on 12/12/18.
//

#ifndef PROJECT_1_BOSSLABEL_H
#define PROJECT_1_BOSSLABEL_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "TextTexture.h"
#include "ElementTexture.h"
#include "Position.h"

class BossLabel {
private:
    std::string name;
    int attackPower;
    int defensePower;
    int maxStamina;
    int stamina;
    bool attacked;
    bool attaking;
public:
    BossLabel(const std::string _name, const int &_attackPower, const int &_defensePower, const int &_stamina,
            const int &_maxStamina, bool _attacked=false,bool _attaking=false):
            attackPower(_attackPower),defensePower(_defensePower),maxStamina(_maxStamina),
            stamina(_stamina),attacked(_attacked),attaking(_attaking),name(_name){};
    void render(const Position &position,SDL_Renderer *gRenderer);
};


#endif //PROJECT_1_BOSSLABEL_H
