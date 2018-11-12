//
// Created by amanda on 04/11/18.
//

#include "CarteTexture.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"


CarteTexture::CarteTexture() {
    cHeight=0;
    cWidth=0;
    cTexture=NULL;
    carte=Carte("hi");
}

CarteTexture::~CarteTexture() {
    free();
}


void CarteTexture::render(SDL_Renderer *gRenderer) {

    ObstacleTexture *o = nullptr;
    LootTexture *l = nullptr;
    DecorationTexture *d=nullptr;
    for (int i = 0; i < carte.getCarte().size(); ++i) {
         if ( o = dynamic_cast<ObstacleTexture*>(carte.getCarte().at(i)) ){

             o->loadImageFromFile(
                     o->getObstacle().getType()
                     ,gRenderer);
             o->render(
                     o->getObstacle().getPosition().getX(),
                     o->getObstacle().getPosition().getY(),
                     NULL,
                     gRenderer
             );
         }
         else if (l = dynamic_cast<LootTexture*>(carte.getCarte().at(i))){
             l->loadImageFromFile("loot03bag.gif",gRenderer);
             l->render(
                     l->getLoot().getPosition().getX(),
                     l->getLoot().getPosition().getY(),
                     NULL,
                     gRenderer
             );
         }
         else if (d = dynamic_cast<DecorationTexture*>(carte.getCarte().at(i))){
             d->loadImageFromFile(d->getDecoration().getType(),gRenderer);
             d->render(
                     d->getDecoration().getPosition().getX(),
                     d->getDecoration().getPosition().getY(),
                     NULL,
                     gRenderer
             );
         }

    }


}


void CarteTexture::free() {
    if (cTexture!=NULL){
        SDL_DestroyTexture(cTexture);
        cTexture=NULL;
        cWidth=0;
        cHeight=0;
    }
}

SDL_Texture *CarteTexture::getCTexture() const {
    return cTexture;
}

void CarteTexture::setCTexture(SDL_Texture *cTexture) {
    CarteTexture::cTexture = cTexture;
}

int CarteTexture::getCWidth() const {
    return cWidth;
}

void CarteTexture::setCWidth(int cWidth) {
    CarteTexture::cWidth = cWidth;
}

int CarteTexture::getCHeight() const {
    return cHeight;
}

void CarteTexture::setCHeight(int cHeight) {
    CarteTexture::cHeight = cHeight;
}

Carte &CarteTexture::getCarte(){
    return carte;
}

void CarteTexture::setCarte(const Carte &carte) {
    CarteTexture::carte = carte;
}
