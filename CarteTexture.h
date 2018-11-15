//
// Created by amanda on 04/11/18.
//

#ifndef PROJECT_1_CARTETEXTURE_H
#define PROJECT_1_CARTETEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Carte.h"
#include "PlayerTexture.h"

class CarteTexture {
private:
    SDL_Texture* cTexture;
    int cWidth;
    int cHeight;
    Carte carte;
    PlayerTexture playerTexture;
    SDL_Rect sdl_rect;

public:
    CarteTexture();

    ~CarteTexture();

    void free();


    void render(SDL_Renderer *gRenderer);


    void render(SDL_Renderer *gRenderer, int a);


    void changeCurrentRender(SDL_Rect *playerRectangle,SDL_Keycode key);


    SDL_Texture *getCTexture() const;

    void setCTexture(SDL_Texture *cTexture);

    int getCWidth() const;

    void setCWidth(int cWidth);

    int getCHeight() const;

    void setCHeight(int cHeight);

    Carte &getCarte();

    void setCarte(const Carte &carte);

    PlayerTexture *getPlayerTexture();

    void setPlayerTexture(PlayerTexture *playerTexture);

    void setPlayerTexture(const PlayerTexture &playerTexture);

    SDL_Rect &getSdl_rect();

    void setSdl_rect(const SDL_Rect &sdl_rect);

    bool allowedMovement(SDL_Keycode key);
};


#endif //PROJECT_1_CARTETEXTURE_H
