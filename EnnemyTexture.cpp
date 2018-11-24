//
// Created by amanda on 22/11/18.
//

#include "EnnemyTexture.h"


void EnnemyTexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer *gRenderer) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, getEWidth(), getEHeight()};
    //Set clip rendering dimensions
    if( clip != nullptr ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, getElementTexture(), clip, &renderQuad );
}

SDL_Rect *EnnemyTexture::getCurrentRect() const {
    return currentRect;
}

void EnnemyTexture::setCurrentRect(SDL_Rect *currentRect) {
    EnnemyTexture::currentRect = currentRect;
}


Ennemy *EnnemyTexture::getEnnemy() const {
    return ennemy;
}

void EnnemyTexture::setEnnemy(Ennemy *ennemy) {
    EnnemyTexture::ennemy = ennemy;
}
