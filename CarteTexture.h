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

class CarteTexture {
private:
    SDL_Texture* cTexture;
    int cWidth;
    int cHeight;
    Carte carte;

public:
    CarteTexture();

    ~CarteTexture();

    void free();


    void render(SDL_Renderer *gRender);

    SDL_Texture *getCTexture() const;

    void setCTexture(SDL_Texture *cTexture);

    int getCWidth() const;

    void setCWidth(int cWidth);

    int getCHeight() const;

    void setCHeight(int cHeight);

    Carte &getCarte();

    void setCarte(const Carte &carte);


};


#endif //PROJECT_1_CARTETEXTURE_H
