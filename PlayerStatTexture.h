//
// Created by amanda on 18/11/18.
//

#ifndef PROJECT_1_PLAYERSTATTEXTURE_H
#define PROJECT_1_PLAYERSTATTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Player.h"

class PlayerStatTexture {
private:
    SDL_Texture *playerStatTexture;
    Player *player;
    Position position;

public:
    PlayerStatTexture();

    virtual ~PlayerStatTexture();

    void render(SDL_Renderer *gRenderer);


    void setPlayer(Player *player);


    void setPosition(const Position &position);
};


#endif //PROJECT_1_PLAYERSTATTEXTURE_H
