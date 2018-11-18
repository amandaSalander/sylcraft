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
public:
    PlayerStatTexture();

    virtual ~PlayerStatTexture();

    void render(SDL_Renderer *gRenderer);

    SDL_Texture *getPlayerStatTexture() const;

    void setPlayerStatTexture(SDL_Texture *playerStatTexture);

    Player *getPlayer() const;

    void setPlayer(Player *player);
};


#endif //PROJECT_1_PLAYERSTATTEXTURE_H
