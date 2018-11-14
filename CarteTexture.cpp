//
// Created by amanda on 04/11/18.
//

#include "CarteTexture.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include "PlayerTexture.h"


CarteTexture::CarteTexture() {
    cHeight=0;
    cWidth=0;
    cTexture=NULL;
    carte=Carte("hi");
    sdl_rect.w=32;
    sdl_rect.h=32;
    sdl_rect.x=0;
    sdl_rect.y=0;

}

CarteTexture::~CarteTexture() {
    free();
}


void CarteTexture::render(SDL_Renderer *gRenderer) {


    Element *e= nullptr;

    for (int i = 0; i < carte.getCarte().size(); ++i) {

         e = carte.getCarte().at(i);

         Obstacle *o= nullptr;
         Decoration *d= nullptr;
         Loot *l= nullptr;

         if (o= dynamic_cast<Obstacle*>(carte.getCarte().at(i))){
            ObstacleTexture obstacleTexture;
            obstacleTexture.loadImageFromFile(
                    o->getType(),
                    gRenderer
                    );
            obstacleTexture.render(o->getPosition().getX(),
                                    o->getPosition().getY(),
                                    NULL,
                                    gRenderer
                    );
         }
        else if (d= dynamic_cast<Decoration*>(carte.getCarte().at(i))){
            DecorationTexture decorationTexture;
            decorationTexture.loadImageFromFile(
                    d->getType(),
                    gRenderer
            );
            decorationTexture.render(d->getPosition().getX(),
                                   d->getPosition().getY(),
                                   NULL,
                                   gRenderer
            );
        }
        else if (l= dynamic_cast<Loot*>(carte.getCarte().at(i))){
             LootTexture lootTexture;
             lootTexture.loadImageFromFile(
                     l->getType(),
                     gRenderer
             );
             lootTexture.render(l->getPosition().getX(),
                                      l->getPosition().getY(),
                                      NULL,
                                      gRenderer
             );
        }






    }


}


void CarteTexture::render(SDL_Renderer *gRenderer, int a){

//    std::cout << "LAYERS " << carte.getLayers().size() << std::endl;
    for (int i = 0; i < carte.getLayers().size(); ++i) {

        for (int j = 0; j < carte.getLayers().at(i).size(); ++j) {

            Obstacle *o= nullptr;
            Decoration *d= nullptr;
            Loot *l= nullptr;
            Player *p= nullptr;

            if (o= dynamic_cast<Obstacle*>(carte.getLayers().at(i).at(j))){

                ObstacleTexture obstacleTexture;
                obstacleTexture.loadImageFromFile(
                        o->getType(),
                        gRenderer
                );
                obstacleTexture.render(o->getPosition().getX(),
                                       o->getPosition().getY(),
                                       NULL,
                                       gRenderer
                );
            }
            else if (l= dynamic_cast<Loot*>(carte.getLayers().at(i).at(j))){

                LootTexture lootTexture;
                lootTexture.loadImageFromFile(
                        l->getType(),
                        gRenderer
                );
                lootTexture.render(l->getPosition().getX(),
                                       l->getPosition().getY(),
                                       NULL,
                                       gRenderer
                );
            }
            else if (d= dynamic_cast<Decoration*>(carte.getLayers().at(i).at(j))){

                DecorationTexture decorationTexture;
                decorationTexture.loadImageFromFile(
                        d->getType(),
                        gRenderer
                );
                decorationTexture.render(d->getPosition().getX(),
                                   d->getPosition().getY(),
                                   NULL,
                                   gRenderer
                );
            }
            else if (p= dynamic_cast<Player*>(carte.getLayers().at(i).at(j))){
                PlayerTexture *playerTexture=new PlayerTexture();
                playerTexture->setPlayer(*p);
                if (playerTexture->loadImageFromFile("katia_civil.png",gRenderer)){

                    playerTexture->render(p->getPosition().getX(),
                                         p->getPosition().getY(),
                                         &sdl_rect,
                                         gRenderer
                    );
                    this->playerTexture= *playerTexture;


                }
                else {
                    std::cout<< "COULDN'T LOAD THE PLAYER" <<std::endl;
                }

            }

        }
    }
}

void CarteTexture::changeCurrentRender(SDL_Rect *playerRectangle, SDL_Keycode key) {

    playerTexture.changeCurrentRender(&sdl_rect,key);
}

void CarteTexture::free() {
    if (cTexture!= nullptr){
        SDL_DestroyTexture(cTexture);
        cTexture=nullptr;
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


void CarteTexture::setPlayerTexture(const PlayerTexture &playerTexture) {
    CarteTexture::playerTexture = playerTexture;
}

SDL_Rect &CarteTexture::getSdl_rect(){
    return sdl_rect;
}

void CarteTexture::setSdl_rect(const SDL_Rect &sdl_rect) {
    CarteTexture::sdl_rect = sdl_rect;
}
