//
// Created by amanda on 22/11/18.
//

#ifndef PROJECT_1_ENNEMYTEXTURE_H
#define PROJECT_1_ENNEMYTEXTURE_H


#include <iostream>
#include "ElementTexture.h"
#include "Ennemy.h"

class EnnemyTexture : public  ElementTexture{
private:
    SDL_Rect *currentRect;
    Ennemy *ennemy;
public :
    void render(int x, int y, SDL_Rect *clip, SDL_Renderer *gRenderer) override;

    SDL_Rect *getCurrentRect() const;

    void setCurrentRect(SDL_Rect *currentRect);

    Ennemy *getEnnemy() const;

    void setEnnemy(Ennemy *ennemy);
};


#endif //PROJECT_1_ENNEMYTEXTURE_H
