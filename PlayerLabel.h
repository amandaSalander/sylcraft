#include <utility>

//
// Created by amanda on 24/11/18.
//

#ifndef PROJECT_1_PLAYERLABEL_H
#define PROJECT_1_PLAYERLABEL_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Position.h"
#include <iostream>
#include "TextTexture.h"

class PlayerLabel {
private:
    int playerNumber;
    bool isCurrentPlayer;
    std::string playerName;
public:
    PlayerLabel(const int &_playerNumber, std::string _playerName,const bool &_isCurrentPlayer=false):playerName(
            std::move(_playerName)),
            playerNumber(_playerNumber), isCurrentPlayer(_isCurrentPlayer){};

    void render(const Position &position,SDL_Renderer *gRenderer);
};


#endif //PROJECT_1_PLAYERLABEL_H
