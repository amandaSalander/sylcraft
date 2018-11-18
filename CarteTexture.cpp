//
// Created by amanda on 04/11/18.
//

#include "CarteTexture.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include "PlayerTexture.h"


CarteTexture::CarteTexture() {
    carte=Carte("hi");
    sdl_rect.w=32;
    sdl_rect.h=32;
    sdl_rect.x=0;
    sdl_rect.y=0;
    playerIndex= -1;
    changedPlayer=false;

}

CarteTexture::~CarteTexture() {
}





void CarteTexture::render(SDL_Renderer *gRenderer){

    int index=0;
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



                PlayerTexture *pT=new PlayerTexture();
                pT->setPlayer(*p);


                if (pT->loadImageFromFile(p->getType(),gRenderer)){


                    /*** THE FIRST PLAYER TO BE ADDED IS ALWAYS THE ONE WHICH IS DIRECTLY SELECTED***/

                    if (playerIndex==-1){playerInMap.push_back(pT);}





                }
                else {
                    std::cout<< "COULDN'T LOAD THE PLAYER" <<std::endl;
                }

            }
            else {
            }

        }
        if (playerIndex==-1){playerIndex=playerInMap.size()-1;}

    }


    if ( playerTexture.getPlayer().getPosition().getY()==0 &&
         playerTexture.getPlayer().getPosition().getX()==0 ){
        playerTexture.getPlayer().setPosition(playerInMap.at(playerIndex)->getPlayer().getPosition());
    }

    SDL_Rect sdl_rect1;
    for (int k = 0; k < playerInMap.size(); ++k) {
        if (k!=playerIndex){


            sdl_rect1.y=0;
            sdl_rect1.x=0;
            sdl_rect1.w=32;
            sdl_rect1.h=32;

            playerInMap.at(k)->render(
                    playerInMap.at(k)->getPlayer().getPosition().getX(),
                    playerInMap.at(k)->getPlayer().getPosition().getY(),
                    &sdl_rect1,
                    gRenderer
            );
        }
        else {
            if (changedPlayer){
                playerTexture= *(playerInMap.at(playerIndex));
                playerInMap.at(playerIndex)->render(
                        playerTexture.getPlayer().getPosition().getX(),
                        playerTexture.getPlayer().getPosition().getY(),
                        &sdl_rect,
                        gRenderer
                );
            }
            else {
                playerInMap.at(playerIndex)->render(
                        playerTexture.getPlayer().getPosition().getX(),
                        playerTexture.getPlayer().getPosition().getY(),
                        &sdl_rect,
                        gRenderer
                );
            }

        }

    }
    changedPlayer=false;

}





Carte &CarteTexture::getCarte(){
    return carte;
}

void CarteTexture::setCarte(const Carte &carte) {
    CarteTexture::carte = carte;
}




SDL_Rect &CarteTexture::getSdl_rect(){
    return sdl_rect;
}



void CarteTexture::updateCurrentPlayer(SDL_Keycode key) {

    switch (key){
        case SDLK_1:
            playerIndex=0;
            break;
        case SDLK_2:
            if (playerInMap.size()>1) {playerIndex=1;}
            break;
        case SDLK_3:
            if (playerInMap.size()>2) {playerIndex=2;}
            break;
        case SDLK_4:
            if (playerInMap.size()>3) {playerIndex=3;}
            break;
        case SDLK_5:
            if (playerInMap.size()>4){ playerIndex=4;}
            break;
        case SDLK_6:
            if (playerInMap.size()>5) playerIndex=5;
            break;
        case SDLK_7:
            if (playerInMap.size()>6) playerIndex=6;
            break;
        case SDLK_8:
            if (playerInMap.size()>7) playerIndex=7;
            break;
        case SDLK_9:
            if (playerInMap.size()>8) playerIndex=8;
            break;
        default:break;

    }
    changedPlayer=true;
}



const std::vector<PlayerTexture *> &CarteTexture::getPlayerInMap() const {
    return playerInMap;
}

void CarteTexture::setPlayerInMap(const std::vector<PlayerTexture *> &playerInMap) {
    CarteTexture::playerInMap = playerInMap;
}

void CarteTexture::changeCurrentRender(SDL_Rect *playerRectangle, SDL_Keycode key) {


    if ( carte.allowedMovement(key,playerTexture.getPlayer().getPosition()) == true){
        playerTexture.changeCurrentRender(&sdl_rect,key);

        carte.updatePosition(playerTexture.getPlayer().getPosition(),playerIndex);
        playerInMap.at(playerIndex)->getPlayer().setPosition(playerTexture.getPlayer().getPosition());

    }





}