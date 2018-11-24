//
// Created by amanda on 04/11/18.
//

#include "CarteTexture.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "DecorationTexture.h"
#include "PlayerTexture.h"
#include "HarmingObjects.h"
#include "HarmingObjectsTexture.h"
#include "NPCTexture.h"
#include "NPC.h"
#include "BubbleTalk.h"
#include "Ennemy.h"
#include "EnnemyTexture.h"


CarteTexture::CarteTexture() {
//    carte=Carte("hi");
    /** pushing three empty SDL_rect in clips, each clip in clips represent
     * current player clip
     * current ennemy clip
     * current boss clip
     * **/
    clips= new std::vector<SDL_Rect*>();
    clips->emplace_back(new SDL_Rect({0,0,32,32}));
    clips->emplace_back(new SDL_Rect({0,32,32,32}));
    clips->emplace_back(new SDL_Rect({0,0,32,32}));
    /** **/
    playerIndex= -1;
    changedPlayer=false;
    currentBubble= nullptr;
    currentNPC= nullptr;
    indexBubble=0;
    playerInMap= new std::vector<PlayerTexture*>();
    initialPositionsOfEnnemies= new std::vector<Position>();
    ennemiesInMap= new std::vector<EnnemyTexture*>();
    switched=false;

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
            else if (auto *h= dynamic_cast<HarmingObjects*>(j)){

                HarmingObjectsTexture harmingObjectsTexture;
                harmingObjectsTexture.loadImageFromFile(
                        h->getType(),
                        gRenderer
                );
                harmingObjectsTexture.render(h->getPosition().getX(),
                                   h->getPosition().getY(),
                                   nullptr,
                                   gRenderer
                );
            }
            else if (auto *n= dynamic_cast<NPC*>(j)){

                NPCTexture npcTexture;
                npcTexture.loadImageFromFile(
                        n->getType(),
                        gRenderer
                );
                npcTexture.render(n->getPosition().getX(),
                                             n->getPosition().getY(),
                                             nullptr,
                                             gRenderer
                );
            }
            else if (auto *e= dynamic_cast<Ennemy*>(j)){


                if (initialPositionsOfEnnemies->size()<3) {
                    initialPositionsOfEnnemies->emplace_back(e->getPosition());


                    EnnemyTexture *ennemyTexture=new EnnemyTexture();
                    ennemyTexture->setEnnemy(e);
                    ennemyTexture->loadImageFromFile(
                            e->getType(),
                            gRenderer
                    );
                    ennemyTexture->render(e->getPosition().getX(),
                                         e->getPosition().getY(),
                                         clips->at(1),
                                         gRenderer
                    );
                    ennemiesInMap->emplace_back(ennemyTexture);
                }



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

                    if (playerIndex==-1){playerInMap->push_back(pT);}

                }
                else {
                    std::cout<< "COULDN'T LOAD THE PLAYER" <<std::endl;
                }

            }
            else {
            }

        }
        if (playerIndex==-1){playerIndex=(int)playerInMap->size()-1;}

    }




        for ( size_t k = 0; k < ennemiesInMap->size(); k++) {
            std::cout << "SWITCHED "<< switched <<std::endl;
            if (!switched && ennemiesInMap->at(k)->getEnnemy()->getPosition().getX() >
                initialPositionsOfEnnemies->at(k).getX()-32
                    ) {
                ennemiesInMap->at(k)->getEnnemy()->setPosition(Position(
                        ennemiesInMap->at(k)->getEnnemy()->getPosition().getX()-1,
                        ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()
                ));
                clips->at(1)=new SDL_Rect({0,32,32,32});
            }
            else if (  initialPositionsOfEnnemies->at(k).getX()-
                       ennemiesInMap->at(k)->getEnnemy()->getPosition().getX()   ==32
                       ){
                switched=true;



            }


            if (switched){

                ennemiesInMap->at(k)->getEnnemy()->setPosition(Position(
                        ennemiesInMap->at(k)->getEnnemy()->getPosition().getX() + 1,
                        ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()
                ));
                clips->at(1)=new SDL_Rect({0,64,32,32});
            }
            if (  ennemiesInMap->at(k)->getEnnemy()->getPosition().getX()-
                        initialPositionsOfEnnemies->at(k).getX()
                          ==32
                    ){
                switched=false;

            }



            ennemiesInMap->at(k)->render(
                    ennemiesInMap->at(k)->getEnnemy()->getPosition().getX(),
                    ennemiesInMap->at(k)->getEnnemy()->getPosition().getY(),
                    clips->at(1),
                    gRenderer
            );
        }



    if ( playerTexture.getPlayer().getPosition().getY()==0 &&
         playerTexture.getPlayer().getPosition().getX()==0 ){
        playerTexture.getPlayer().setPosition(playerInMap->at((size_t) playerIndex)->getPlayer().getPosition());
    }

    SDL_Rect sdl_rect1;
    for (size_t k = 0; k < playerInMap->size(); ++k) {
        if (k!=playerIndex){


            sdl_rect1.y=0;
            sdl_rect1.x=0;
            sdl_rect1.w=32;
            sdl_rect1.h=32;

            playerInMap->at(k)->render(
                    playerInMap->at(k)->getPlayer().getPosition().getX(),
                    playerInMap->at(k)->getPlayer().getPosition().getY(),
                    &sdl_rect1,
                    gRenderer
            );
        }
        else {
            if (changedPlayer){
                playerTexture= *(playerInMap->at((size_t)playerIndex));
                playerInMap->at((size_t)playerIndex)->render(
                        playerTexture.getPlayer().getPosition().getX(),
                        playerTexture.getPlayer().getPosition().getY(),
                        clips->at(0),
                        gRenderer
                );
            }
            else {
                playerInMap->at((size_t)playerIndex)->render(
                        playerTexture.getPlayer().getPosition().getX(),
                        playerTexture.getPlayer().getPosition().getY(),
                        clips->at(0),
                        gRenderer
                );
            }

        }

    }
    if (currentBubble!= nullptr &&  currentNPC!= nullptr){
        currentBubble->render(currentNPC->getName(),currentNPC->getPrompts().at(indexBubble),gRenderer);
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
            if (playerInMap->size()>1) {playerIndex=1;}
            break;
        case SDLK_3:
            if (playerInMap->size()>2) {playerIndex=2;}
            break;
        case SDLK_4:
            if (playerInMap->size()>3) {playerIndex=3;}
            break;
        case SDLK_5:
            if (playerInMap->size()>4){ playerIndex=4;}
            break;
        case SDLK_6:
            if (playerInMap->size()>5) playerIndex=5;
            break;
        case SDLK_7:
            if (playerInMap->size()>6) playerIndex=6;
            break;
        case SDLK_8:
            if (playerInMap->size()>7) playerIndex=7;
            break;
        case SDLK_9:
            if (playerInMap->size()>8) playerIndex=8;
            break;
        default:break;

    }
    changedPlayer=true;
}



void CarteTexture::changeCurrentRender(SDL_Keycode key,float &timestep,float &start,SDL_Renderer *gRenderer) {


    if ( carte->allowedMovement(key,playerTexture.getPlayer().getPosition())){
        playerTexture.changeCurrentRender(clips->at(0),key);
//
        carte->updatePosition(playerTexture.getPlayer().getPosition(),playerIndex);

        if (playerInMap->size()==0){
            std::cout << "LOL" <<std::endl;
        }
        else {
            std::cout << "POP" <<std::endl;
            playerInMap->at((size_t)playerIndex)->getPlayer().setPosition(playerTexture.getPlayer().getPosition());
        }

// playerInMap->at((size_t)playerIndex)->getPlayer().setPosition(playerTexture.getPlayer().getPosition());

        Position position= carte->isHarming(playerTexture.getPlayer().getPosition(),timestep,start);
        int index= position.getY()/32*30+position.getX()/32;
        HarmingObjects *harmingObjects= dynamic_cast<HarmingObjects*>(carte->getLayers()->back().at(index));
        if (position.getX()==-1 && position.getY()==-1){
//
        }
        else {
            playerTexture.getPlayer().getClasse()->setStamina(
                    playerTexture.getPlayer().getClasse()->getStamina()-
                        harmingObjects->getStamina()
                    );
            auto *playerMapTemp= new std::vector<PlayerTexture*>();
            for (int i = 0; i <playerInMap->size() ; ++i) {
                if (playerInMap->at(i)->getPlayer().getClasse()->getStamina()==0){
                    playerIndex=0;
                }else {
                    playerMapTemp->emplace_back(playerInMap->at(i));
                }
            }
            playerInMap=playerMapTemp;


        }


        Position npcPosition=carte->allowedTalkToNPC(playerTexture.getPlayer().getPosition());

        if (key==SDLK_c) {
            if (npcPosition.getY() == -1 && npcPosition.getX() == -1) {

            } else {

                 currentBubble= new BubbleTalk(
                         new Position(
                                 npcPosition.getX()-100,
                                 npcPosition.getY() - 60
                         )
                         );

                currentNPC = dynamic_cast<NPC *>(
                        carte->getLayers()->back().at(
                                (size_t)npcPosition.getY()/32*30+npcPosition.getX()/32
                                )
                );

                std::cout << "I AM HERE" <<std::endl;


            }
        }

    }
    if (currentNPC!= nullptr && key ==SDLK_k){
        if (indexBubble+1 < currentNPC->getPrompts().size()){
            ++indexBubble;
        }
        else {
            currentNPC= nullptr;
            currentBubble= nullptr;
            indexBubble=0;
        }
        }
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