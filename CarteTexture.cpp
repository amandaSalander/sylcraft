//
// Created by amanda on 04/11/18.
//

#include "CarteTexture.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include "PlayerTexture.h"


CarteTexture::CarteTexture() {
//    carte=Carte("hi");
    sdl_rect.w=32;
    sdl_rect.h=32;
    sdl_rect.x=0;
    sdl_rect.y=0;
    playerIndex= -1;
    changedPlayer=false;

}

CarteTexture::~CarteTexture() = default;


void CarteTexture::render(SDL_Renderer *gRenderer){
//    lootInMap.clear();

    for (const auto &i : *(carte->getLayers()) ) {

        for (auto j : i) {

            if (auto *o= dynamic_cast<Obstacle*>(j)){

                ObstacleTexture obstacleTexture;
                obstacleTexture.loadImageFromFile(
                        o->getType(),
                        gRenderer
                );
                obstacleTexture.render(o->getPosition().getX(),
                                       o->getPosition().getY(),
                                       nullptr,
                                       gRenderer
                );
            }
            else if (auto *l= dynamic_cast<Loot*>(j)){

                LootTexture lootTexture;
                lootTexture.loadImageFromFile(
                        l->getType(),
                        gRenderer
                );
                lootTexture.render(l->getPosition().getX(),
                                       l->getPosition().getY(),
                                   nullptr,
                                       gRenderer
                );
            }
            else if (auto *d= dynamic_cast<Decoration*>(j)){

                DecorationTexture decorationTexture;
                decorationTexture.loadImageFromFile(
                        d->getType(),
                        gRenderer
                );
                decorationTexture.render(d->getPosition().getX(),
                                   d->getPosition().getY(),
                                         nullptr,
                                   gRenderer
                );
            }
            else if (auto *p= dynamic_cast<Player*>(j)){


                auto *pT=new PlayerTexture();
                pT->setPlayer(*p);


                if (pT->loadImageFromFile(p->getType(),gRenderer)){

                    if (playerIndex==-1){playerInMap.push_back(pT);}

                }
                else {
                    std::cout<< "COULDN'T LOAD THE PLAYER" <<std::endl;
                }

            }
            else {
            }

        }
        if (playerIndex==-1){playerIndex=(int)playerInMap.size()-1;}

    }


    if ( playerTexture.getPlayer().getPosition().getY()==0 &&
         playerTexture.getPlayer().getPosition().getX()==0 ){
        playerTexture.getPlayer().setPosition(playerInMap.at((size_t) playerIndex)->getPlayer().getPosition());
    }

    SDL_Rect sdl_rect1;
    for (size_t k = 0; k < playerInMap.size(); ++k) {
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
                playerTexture= *(playerInMap.at((size_t)playerIndex));
                playerInMap.at((size_t)playerIndex)->render(
                        playerTexture.getPlayer().getPosition().getX(),
                        playerTexture.getPlayer().getPosition().getY(),
                        &sdl_rect,
                        gRenderer
                );
            }
            else {
                playerInMap.at((size_t)playerIndex)->render(
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





Carte *CarteTexture::getCarte(){
    return carte;
}

void CarteTexture::setCarte(Carte *carte) {
    this->carte = carte;
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



//const std::vector<PlayerTexture *> &CarteTexture::getPlayerInMap() const {
//    return playerInMap;
//}

//void CarteTexture::setPlayerInMap(const std::vector<PlayerTexture *> &playerInMap) {
//    CarteTexture::playerInMap = playerInMap;
//}

void CarteTexture::changeCurrentRender(SDL_Keycode key) {


    if ( carte->allowedMovement(key,playerTexture.getPlayer().getPosition())){
        playerTexture.changeCurrentRender(&sdl_rect,key);

        carte->updatePosition(playerTexture.getPlayer().getPosition(),playerIndex);
        playerInMap.at((size_t)playerIndex)->getPlayer().setPosition(playerTexture.getPlayer().getPosition());

    }
    std::cout << "PICKING STATE : ( " << carte->allowedPick(playerTexture.getPlayer().getPosition()).getX()
    <<" , " << carte->allowedPick(playerTexture.getPlayer().getPosition()).getY() << " ) " <<std::endl;

}

void CarteTexture::PickUpLoot(SDL_Keycode key) {
    switch (key){
        case SDLK_a:
        {
            Position pos=carte->allowedPick(playerTexture.getPlayer().getPosition());
            if (pos.getX()==-1 && pos.getY()==-1){
                std::cout << "Cannot delete empty case you dumbass " <<std::endl;
            }
            else {
                Loot loot=carte->deleteLoot(pos);
                std::cout << "strength : "<< loot.getStrength() <<std::endl;
                std::cout << "stamina : "<< loot.getStamina() <<std::endl;
                std::cout << "defense : "<< loot.getDefense() <<std::endl;
                std::cout << "luck : "<< loot.getLuck() <<std::endl;

                playerTexture.getPlayer().getClasse()->setStrength(
                        playerTexture.getPlayer().getClasse()->getStrength()+
                        loot.getStrength());
                playerTexture.getPlayer().getClasse()->setDefense(
                        playerTexture.getPlayer().getClasse()->getDefense()+
                        loot.getDefense());
                playerTexture.getPlayer().getClasse()->setStamina(
                        playerTexture.getPlayer().getClasse()->getStamina()+
                        loot.getStamina());
                playerTexture.getPlayer().getClasse()->setLuck(
                        playerTexture.getPlayer().getClasse()->getLuck()+ loot.getLuck());

            }

            carte->updatePlayerStat(playerTexture.getPlayer(),playerIndex);

            std::cout << "*********************************************************************" <<std::endl;
            std::cout << "PLAYER STRENGTH : "<< playerTexture.getPlayer().getClasse()->getStrength()<<std::endl;
            std::cout << "PLAYER STAMINA : "<< playerTexture.getPlayer().getClasse()->getStamina()<<std::endl;
            std::cout << "PLAYER DEFENSE : "<< playerTexture.getPlayer().getClasse()->getDefense()<<std::endl;
            std::cout << "PLAYER LUCK : "<< playerTexture.getPlayer().getClasse()->getLuck()<<std::endl;
            std::cout << "*********************************************************************" <<std::endl;
        }
            break;
        default:break;
    }
}