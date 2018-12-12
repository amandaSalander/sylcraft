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
#include "PlayerLabel.h"
#include "EnnemyLabel.h"
#include "ItemTexture.h"
#include "Boss.h"
#include "BossTexture.h"
#include "BossLabel.h"


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
    frame=0;
    renderCurrentPlayer=true;
    currentEnnemy=-1;
    numberOfEnnemies=0;
    ennemyInMovement= nullptr;
    indexEnnemyInMovement=-1;
    displayQuest=-1;
    bossTexture= nullptr;
}


CarteTexture::~CarteTexture() = default;


void CarteTexture::render(SDL_Renderer *gRenderer){
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
            else if(auto *b= dynamic_cast<Boss*>(j)){
                BossTexture bossTexture;
                bossTexture.loadImageFromFile(
                        b->getType(),
                        gRenderer
                        );

                bossTexture.render(b->getPosition().getX(),
                                   b->getPosition().getY(),
                                   clips->at(2),
                                   gRenderer
                );
                bossTexture.setBoss(b);
                this->bossTexture=new BossTexture(bossTexture);

                BossLabel *bossLabel= nullptr;

                if (playerTexture.getPlayer().getClasse()){
                    if (playerTexture.getPlayer().getClasse()->getMargin_attack()){
                        bossLabel=new BossLabel(
                                b->getName(),
                                b->getAttack_strength(),
                                b->getDefense_strength(),
                                b->getStamina(),
                                b->getMax_stamina(),
                                playerIsAllowedToAttackBoss(
                                        playerTexture.getPlayer().getPosition(),
                                        playerTexture.getPlayer().getClasse()->getMargin_attack()
                                ),
                                bossIsAllowedToAttackPlayer(
                                        playerTexture.getPlayer().getPosition(),
                                        b->getMargin_detection()
                                        )
                        );
                    }
                    else {
                        bossLabel=new BossLabel(
                                b->getName(),
                                b->getAttack_strength(),
                                b->getDefense_strength(),
                                b->getStamina(),
                                b->getMax_stamina(),
                                playerIsAllowedToAttackBoss(
                                        playerTexture.getPlayer().getPosition()
                                )
                        );
                    }
                }else {
                    bossLabel=new BossLabel(
                            b->getName(),
                            b->getAttack_strength(),
                            b->getDefense_strength(),
                            b->getStamina(),
                            b->getMax_stamina(),
                            playerIsAllowedToAttackBoss(
                                    playerTexture.getPlayer().getPosition()
                            )
                    );
                }


                bossLabel->render(
                        Position(b->getPosition().getX()+4,
                                b->getPosition().getY()-32),
                                gRenderer
                        );

                bossAttack(playerTexture.getPlayer().getPosition());
            }
            else if (auto *l= dynamic_cast<Loot*>(j)){

                LootTexture lootTexture;
                lootTexture.loadImageFromFile(
                        l->getType(),
                        gRenderer
                );

                SDL_Rect *rect= new SDL_Rect({0,0,32,32});
                if (frame%4==0){
                    rect->x=0;
                }
                else if (frame%4==1){
                    rect->x=32;
                }
                else if (frame%4==2){
                    rect->x=64;
                }
                else if (frame%4==3){
                    rect->x=96;
                }
                lootTexture.render(l->getPosition().getX(),
                                       l->getPosition().getY(),
                                   rect,
                                       gRenderer
                );
            }
            else if (auto *h= dynamic_cast<HarmingObjects*>(j)){
                auto *rect=new SDL_Rect({0,0,32,32});
                if (frame%15==0){
                    rect->x=0;
                } else if (frame%15==1){
                    rect->x=32;
                } else if (frame%15==2){
                    rect->x=64;
                } else if (frame%15==3){
                    rect->x=96;
                }
                else if (frame%15==4){
                    rect->x=128;
                }
                else if (frame%15==5){
                    rect->x=160;
                }
                else if (frame%15==6){
                    rect->x=192;
                }
                else if (frame%15==7){
                    rect->x=224;
                }
                else if (frame%15==8){
                    rect->x=256;
                }
                else if (frame%15==9){
                    rect->x=288;
                }
                else if (frame%15==10){
                    rect->x=320;
                }
                else if (frame%15==11){
                    rect->x=352;
                }
                else if (frame%15==12){
                    rect->x=384;
                }
                else if (frame%15==13){
                    rect->x=416;
                }
                else if (frame%15==14){
                    rect->x=448;
                }

                HarmingObjectsTexture harmingObjectsTexture;
                harmingObjectsTexture.loadImageFromFile(
                        h->getType(),
                        gRenderer
                );
                harmingObjectsTexture.render(h->getPosition().getX(),
                                   h->getPosition().getY(),
                                   rect,
                                   gRenderer
                );
                frame= (frame+1)%15;
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
                if (n->getQuests()!= nullptr && !n->allQuestCleaned()){
                    ElementTexture elementTexture;
                    elementTexture.loadImageFromFile("assets/tiles/gem_01a.png",gRenderer);
                    elementTexture.render(
                            n->getPosition().getX()+8,
                            n->getPosition().getY()-16,
                            nullptr,
                            gRenderer
                    );
                }

            }
            else if (auto *item= dynamic_cast<Item*>(j)){


                if (item->isFound())continue;
                else {
                    ItemTexture itemtexture;
                    SDL_Rect *rect= new SDL_Rect({0,0,32,32});
                    itemtexture.loadImageFromFile(
                            item->getType(),
                            gRenderer
                    );
                    itemtexture.render(item->getPosition().getX(),
                                       item->getPosition().getY(),
                                       rect,
                                       gRenderer
                    );
                }


            }
            else if (auto *e= dynamic_cast<Ennemy*>(j)){

                    bool firstRender=true;
                    if (numberOfEnnemies!=0){
                        firstRender=false;
                    }
                    if (firstRender){
                        auto *ennemyTexture=new EnnemyTexture();
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
                        initialPositionsOfEnnemies->emplace_back(e->getPosition());
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
                if (playerIndex==-1){playerInMap->push_back(pT);}

            }

        }
        if (playerIndex==-1){playerIndex=(int)playerInMap->size()-1;}

    }

    numberOfEnnemies= static_cast<int>(ennemiesInMap->size());


        /** Handling ennemies here **/

        for ( size_t k = 0; k < ennemiesInMap->size(); k++) {
            if (ennemiesInMap->at(k)!= nullptr && k!=indexEnnemyInMovement ){
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
                auto *ennemyLabel=new EnnemyLabel(
                        ennemiesInMap->at(k)->getEnnemy()->getAttackEffect(),
                        ennemiesInMap->at(k)->getEnnemy()->getDefenseEffect(),
                        ennemiesInMap->at(k)->getEnnemy()->getStamina(),
                        ennemiesInMap->at(k)->getEnnemy()->getMax_stamina(),
                        false,
                        ennemyIsAllowedToAttack(k,ennemiesInMap->at(k)->getEnnemy()->getMargin_detection())
                );
                ennemyAttack(k);

                if (playerTexture.getPlayer().getClasse()){
                    if (playerTexture.getPlayer().getClasse()->getMargin_attack())
                        currentEnnemy= playerIsAllowedToAttack(playerTexture.getPlayer().getPosition(),
                                playerTexture.getPlayer().getClasse()->getMargin_attack()
                        );
                    else{
                        currentEnnemy= playerIsAllowedToAttack(playerTexture.getPlayer().getPosition(),
                                                               32
                        );
                    }
                }else {
                    currentEnnemy= playerIsAllowedToAttack(playerTexture.getPlayer().getPosition(),
                                                           32
                    );
                }

                ennemyLabel->setAttacked(currentEnnemy == k);


                ennemiesInMap->at(k)->render(
                        ennemiesInMap->at(k)->getEnnemy()->getPosition().getX(),
                        ennemiesInMap->at(k)->getEnnemy()->getPosition().getY(),
                        clips->at(1),
                        gRenderer
                );
                ennemyLabel->render(
                        Position(ennemiesInMap->at(k)->getEnnemy()->getPosition().getX()+4,
                                 ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()-20),
                        gRenderer
                );
            }

        }



    if ( playerTexture.getPlayer().getPosition().getY()==0 &&
         playerTexture.getPlayer().getPosition().getX()==0 ){
        playerTexture.getPlayer().setPosition(playerInMap->at((size_t) playerIndex)->getPlayer().getPosition());
    }

    SDL_Rect sdl_rect1;
    for (size_t k = 0; k < playerInMap->size(); k++) {
        auto *playerLabel= new PlayerLabel(
                static_cast<const int &>(k + 1),
                playerInMap->at(k)->getPlayer().getName(),
                k==playerIndex);

        if (k!=playerIndex){
            sdl_rect1.y=0;sdl_rect1.x=0;sdl_rect1.w=32;sdl_rect1.h=32;

            playerInMap->at(k)->loadImageFromFile(
                    playerInMap->at(k)->getPlayer().getType(),
                    gRenderer
                    );
            playerInMap->at(k)->render(
                    playerInMap->at(k)->getPlayer().getPosition().getX(),
                    playerInMap->at(k)->getPlayer().getPosition().getY(),
                    &sdl_rect1,
                    gRenderer
            );

        }
        else {
            if (renderCurrentPlayer){
                if (changedPlayer){
                    playerTexture= *(playerInMap->at((size_t)playerIndex));
                }
                playerInMap->at((size_t)playerIndex)->loadImageFromFile(
                        playerInMap->at((size_t)playerIndex)->getPlayer().getType(),gRenderer);

            }else {
                if (changedPlayer){
                    std::string tmp=playerTexture.getPlayer().getType().substr(0,
                            playerTexture.getPlayer().getType().find('.'));
                    tmp+="_harm.png";

                    playerTexture= *(playerInMap->at((size_t)playerIndex));
                    playerInMap->at((size_t)playerIndex)->loadImageFromFile(tmp,gRenderer);
                }else {
                    playerInMap->at((size_t)playerIndex)->loadImageFromFile(
                            playerInMap->at((size_t)playerIndex)->getPlayer().getType(),gRenderer);

                }

            }

            playerInMap->at(k)->render(
                    playerInMap->at(k)->getPlayer().getPosition().getX(),
                    playerInMap->at(k)->getPlayer().getPosition().getY(),
                    clips->at(0),
                    gRenderer
            );

        }
        playerLabel->render(
                Position( playerInMap->at(k)->getPlayer().getPosition().getX()+4,
                          playerInMap->at(k)->getPlayer().getPosition().getY()-20),
                gRenderer);

    }
    if (currentBubble!= nullptr &&  currentNPC!= nullptr ){
        if (displayQuest==-1){
            currentBubble->render(currentNPC->getName(),currentNPC->getPrompts().at(indexBubble),gRenderer);
        }else {
            if (currentNPC->getQuests()!= nullptr){
                size_t nextAvailableQuest(0);
                for (int i = 0; i < currentNPC->getQuests()->size(); ++i) {
                    if( currentNPC->getQuests()->at(i)->getQuest_state()==QUEST_ONGOING){
                        nextAvailableQuest++;
                    }
                }
                std::cout << "BUBBLE INDEX "<< indexBubble <<std::endl;
                /** checking if there is still a quest to show **/
                if (nextAvailableQuest <currentNPC->getQuests()->size()){
                    if (indexBubble < currentNPC->getQuests()->at(nextAvailableQuest)->getTalks()->size() ){
                        currentBubble->render(currentNPC->getQuests()->at(nextAvailableQuest)->getTitle(),
                                              currentNPC->getQuests()->at(nextAvailableQuest)->getTalks()->at(indexBubble),
                                              gRenderer);
                    }

                }

            }

        }

    }
    changedPlayer=false;

    clips->at(2)=new SDL_Rect({32*(frame%3),0,32,32});
    /** START **/
    /** CHECK AT EACH RENDER IF A PLAYER CAN ATTACK **/




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



void CarteTexture::changeCurrentRender(SDL_Keycode key,float &timestep,float &start) {

    size_t nextAvailableQuest(0);

    if(key== SDLK_x){
        playerAttack();
    }

    if ( carte->allowedMovement(key,playerTexture.getPlayer().getPosition())){
        playerTexture.changeCurrentRender(clips->at(0),key);

        carte->updatePosition(playerTexture.getPlayer().getPosition(),playerIndex);

        if (playerInMap->empty()){}
        else {
            playerInMap->at((size_t)playerIndex)->getPlayer().setPosition(playerTexture.getPlayer().getPosition());
        }


        Position position= carte->isHarming(playerTexture.getPlayer().getPosition(),timestep,start);
        int index= position.getY()/32*30+position.getX()/32;
        auto *harmingObjects= dynamic_cast<HarmingObjects*>(carte->getLayers()->back().at(
                static_cast<unsigned long>(index)));
        if (position.getX()==-1 && position.getY()==-1){
            renderCurrentPlayer=true;
        }
        else {
            playerTexture.getPlayer().getClasse()->setStamina(
                    playerTexture.getPlayer().getClasse()->getStamina()-
                        harmingObjects->getStamina()
                    );

            renderCurrentPlayer=false;

            auto *playerMapTemp= new std::vector<PlayerTexture*>();
            for (auto &i : *playerInMap) {
                if (i->getPlayer().getClasse()->getStamina()<=0){
                    playerIndex=0;
                    renderCurrentPlayer=true;
                }else {
                    playerMapTemp->emplace_back(i);
                }
            }
            playerInMap=playerMapTemp;

        }


        Position npcPosition=carte->allowedTalkToNPC(playerTexture.getPlayer().getPosition());

        if (key==SDLK_z){
            if (auto a=carte->pickItem(playerTexture.getPlayer().getPosition())){
                playerTexture.getPlayer().addToIventory(new Item(*a));
            }

        }
        if (key==SDLK_c || key==SDLK_v) {


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

                displayQuest=-1;

                if (currentNPC->getQuests()){
                    for (auto &i : *currentNPC->getQuests()) {
                        if (i->getQuest_state()==QUEST_COMPLETED){

                            for (int j = 0; j < i->getGifts()->size(); ++j) {
                                auto ll= i->getGifts()->at(static_cast<unsigned long>(j));
                                ll->setPosition(Position(
                                        currentNPC->getPosition().getX()+32*(j%2),
                                        currentNPC->getPosition().getY()+32-32*(j%2)
                                ));

                                carte->addLootToMap(ll);
                            }

                            i->setQuest_state(QUEST_ONGOING);
                        }
                    }
                }


            }
            if (key==SDLK_v){
                displayQuest=1;
                indexBubble=0;

            }
            if (key==SDLK_c){
                indexBubble=0;
                displayQuest=-1;
            }
        }


    }
    if (currentNPC){
        for(auto &k: *currentNPC->getQuests()){
            if (k->getQuest_state()==QUEST_ONGOING || k->getQuest_state()==QUEST_COMPLETED){
                nextAvailableQuest++;
                std::cout << "NEXT "<< nextAvailableQuest <<std::endl;
            }
        }
    }
    if (currentNPC!= nullptr && key ==SDLK_k){

        std::cout << "available quest is " << nextAvailableQuest <<std::endl;
        if (indexBubble+1 < currentNPC->getPrompts().size()){
            ++indexBubble;
        }
        else if (displayQuest!=-1){

            /** if nextAvailableQuest superior to or equal to size of quest we do not show anything **/
            if (nextAvailableQuest < currentNPC->getQuests()->size()){
                if (indexBubble+1 < currentNPC->getQuests()->at(nextAvailableQuest)->getTalks()->size()){
                    ++indexBubble;
                }
                else {
                    currentNPC= nullptr;
                    currentBubble= nullptr;
                    indexBubble=0;
                }
            }else {
                currentNPC= nullptr;
                currentBubble= nullptr;
                indexBubble=0;
            }

        }
        else {
            currentNPC= nullptr;
            currentBubble= nullptr;
            indexBubble=0;
        }
        }

        if (playerTexture.getPlayer().getPosition().getY()<bossTexture->getBoss()->getPosition().getY()){
            clips->at(2)=new SDL_Rect({clips->at(2)->x,96,32,32});
        }else {
            clips->at(2)=new SDL_Rect({clips->at(2)->x,0,32,32});
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
        }
            break;
        default:break;
    }
}


int CarteTexture::playerIsAllowedToAttack(const Position &position, const int &margin) {

    int a=-1;
    int distance;
    for (size_t l = 0; l < ennemiesInMap->size() ; ++l) {
        if (ennemiesInMap->at(l)!= nullptr){
            distance =(int) sqrt(
                    pow(playerTexture.getPlayer().getPosition().getX()-
                        ennemiesInMap->at(l)->getEnnemy()->getPosition().getX()
                            ,2)+
                    pow(playerTexture.getPlayer().getPosition().getY()-
                        ennemiesInMap->at(l)->getEnnemy()->getPosition().getY()
                            ,2)
            ) ;
            if (margin> distance){
                a= static_cast<int>(l);
            break;
            }
        }

    }
    return a;

}

bool CarteTexture::ennemyIsAllowedToAttack(const size_t &k, const int &margin) {

    bool a=false;
    int distance;
    if (ennemiesInMap->at(k)!= nullptr){
        distance =(int) sqrt(
                pow(playerTexture.getPlayer().getPosition().getX()-
                    ennemiesInMap->at(k)->getEnnemy()->getPosition().getX()
                        ,2)+
                pow(playerTexture.getPlayer().getPosition().getY()-
                    ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()
                        ,2)) ;
        if (distance<margin) a=true;
    }

    return a;
}

void CarteTexture::ennemyAttack(const size_t &k) {

    /** in this context allowed to attack mean that the ennemy can get near the player **/
    if (  ennemyIsAllowedToAttack( k,ennemiesInMap->at(k)->getEnnemy()->getMargin_detection() ) ){
    std::cout << "I AM HERE"  <<std::endl;
        ennemyInMovement=ennemiesInMap->at(k);
        indexEnnemyInMovement=(int)k;
        double a= (playerTexture.getPlayer().getPosition().getY()-ennemyInMovement->getEnnemy()->getPosition().getY())*1.0/
                (playerTexture.getPlayer().getPosition().getX()-ennemyInMovement->getEnnemy()->getPosition().getX());
        double b= playerTexture.getPlayer().getPosition().getY()-a*playerTexture.getPlayer().getPosition().getX();

        std::cout << "A : "<<a <<std::endl;
        std::cout << "B : "<<b <<std::endl;

        /** if a >0 and ennemy x position is smaller than current player x position
         * increment x of ennemey each frame by 1
         * and update y position of ennemey according to the values of a and b by y=ax+b
         * **/
        auto val =ennemyInMovement->getEnnemy()->getPosition().getX();
        if (a>0 && val < playerTexture.getPlayer().getPosition().getX() ){
            ennemyInMovement->getEnnemy()->setPosition(
                    Position(
                          val+1,
                          static_cast<int>(a * (val + 1) + b)
                            )
                    );
        }
        else if( a>0 && val > playerTexture.getPlayer().getPosition().getX() ){
            ennemyInMovement->getEnnemy()->setPosition(
                    Position(
                            val-1,
                            static_cast<int>(a * (val -1) + b)
                    )
            );
        }
        else if (a<0 && val < playerTexture.getPlayer().getPosition().getX() ){
            ennemyInMovement->getEnnemy()->setPosition(
                    Position(
                            val+1,
                            static_cast<int>(a * (val + 1) + b)
                    )
            );
        }else {
            ennemyInMovement->getEnnemy()->setPosition(
                    Position(
                            val-1,
                            static_cast<int>(a * (val -1) + b)
                    )
            );
        }

        /** if the ennemy is near the player to attack him **/
        if (ennemyIsAllowedToAttack(k,ennemiesInMap->at(k)->getEnnemy()->getMargin_attack())){
            std::cout << "I CAN KICK THE PLAYER"<<std::endl;
            if (ennemiesInMap->at(k)->getEnnemy()->getAttackEffect()>0){
                playerTexture.getPlayer().getClasse()->setStamina(
                        playerTexture.getPlayer().getClasse()->getStamina()-1
                );
                ennemiesInMap->at(k)->getEnnemy()->setAttackEffect(
                        ennemiesInMap->at(k)->getEnnemy()->getAttackEffect()-1
                );
                /** renderCurrentPlayer to false means that the player is injured **/
                renderCurrentPlayer= false;
                updatePlayersInMap();
            } else{ renderCurrentPlayer=true;}

        }




    }
    /** replace it with reset method **/
    else if( ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()!=initialPositionsOfEnnemies->at(k).getY() ){

        double a= (initialPositionsOfEnnemies->at(k).getY()-
                ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()*1.0 )/
                  (initialPositionsOfEnnemies->at(k).getX()-ennemiesInMap->at(k)->getEnnemy()->getPosition().getX() );
        double b= initialPositionsOfEnnemies->at(k).getY()
                -a*initialPositionsOfEnnemies->at(k).getX();



        if (abs(a)>5) a=5;
        if (abs(b)>1000)b=1000;

        int val= ennemiesInMap->at(k)->getEnnemy()->getPosition().getX();
        int val2=initialPositionsOfEnnemies->at(k).getX();

        /** sometimes a and b are too much large so the ennemies get out of the map
         * to contain that if the position y is too large we set it directly back to the initial position **/
        auto v1= static_cast<int>(a * (val + 1) + b);
        auto v2= static_cast<int>(a * (val - 1) + b);
        if (abs(v2)>1000) v2=initialPositionsOfEnnemies->at(k).getY();
        if (abs(v1)>1000) v1=initialPositionsOfEnnemies->at(k).getY();
        if (a>0 && val < val2){
            ennemiesInMap->at(k)->getEnnemy()->setPosition(
                    Position(
                            val+1,
                            v1
                    )
            );
        }
        else if( a>0 && val > val2 ){
            ennemiesInMap->at(k)->getEnnemy()->setPosition(
                    Position(
                            val-1,
                            v2
                    )
            );
        }
        else if (a<0 && val < val2 ){
            ennemiesInMap->at(k)->getEnnemy()->setPosition(
                    Position(
                            val+1,
                            v1
                    )
            );
        }else {
            ennemiesInMap->at(k)->getEnnemy()->setPosition(
                    Position(
                            val-1,
                            v2
                    )
            );
        }


    }
    else {
        /**
         if the ennemy is in its initial position, it stays in it's random position  **/
        indexEnnemyInMovement=-1;
    }

    /* std::cout << "("<<ennemiesInMap->at(k)->getEnnemy()->getPosition().getX() <<"," <<
    ennemiesInMap->at(k)->getEnnemy()->getPosition().getY()<< ")" <<std::endl; */
}

void CarteTexture::updatePlayersInMap() {
    auto *playerMapTemp= new std::vector<PlayerTexture*>();
    for (auto &i : *playerInMap) {
        if (i->getPlayer().getClasse()->getStamina()<=0){
            playerIndex=0;
            renderCurrentPlayer=true;
        }else {
            playerMapTemp->emplace_back(i);
        }
    }
    playerInMap=playerMapTemp;
}

void CarteTexture::updateEnnemiesInMap() {

    for (size_t i = 0; i <ennemiesInMap->size() ; ++i) {
        if (ennemiesInMap->at(i)->getEnnemy()->getStamina()==0){

            auto *l =new Loot("heart");
            l->setPosition(Position (ennemiesInMap->at(i)->getEnnemy()->getPosition()));
            carte->addLootToMap(l);
            ennemiesInMap->erase(ennemiesInMap->begin() + i);
            initialPositionsOfEnnemies->erase(initialPositionsOfEnnemies->begin()+i);
        }
    }

}

void CarteTexture::playerAttack() {


        int a=playerTexture.getPlayer().getClasse()->attackPower(5);
        auto k= (unsigned long)currentEnnemy;
        if (currentEnnemy!=-1 && ennemiesInMap->at(k)!= nullptr) {

            if (a >= ennemiesInMap->at(k)->getEnnemy()->getStamina()) {
                ennemiesInMap->at(k)->getEnnemy()->setStamina(0);
                updateEnnemiesInMap();
                currentEnnemy=-1;
            } else {
                ennemiesInMap->at(k)->getEnnemy()->setStamina(
                        ennemiesInMap->at(k)->getEnnemy()->getStamina()
                        - a);

            }

            playerTexture.getPlayer().getClasse()->setStrength(
                    (int) (playerTexture.getPlayer().getClasse()->getStrength() / 1.33)
            );
            if (playerTexture.getPlayer().getClasse()->getStrength() <=3){
                playerTexture.getPlayer().getClasse()->setStrength(0);
            }

        }
}

void CarteTexture::resetEnnemyPosition() {
    for (size_t i = 0; i <ennemiesInMap->size() ; ++i) {
        if (ennemiesInMap->at(i)->getEnnemy()->getPosition().getY() !=
            initialPositionsOfEnnemies->at(i).getY()
        ){
            std::cout << "I AM HERE " <<std::endl;
            /** calculate the line y=ax+b that make the ennemy come back to its original place **/
            double a= (initialPositionsOfEnnemies->at(i).getY()-
                    ennemiesInMap->at(i)->getEnnemy()->getPosition().getY())*1.0/
                      (initialPositionsOfEnnemies->at(i).getX()-
                      ennemiesInMap->at(i)->getEnnemy()->getPosition().getX());

            double b= initialPositionsOfEnnemies->at(i).getY()-a*
                    initialPositionsOfEnnemies->at(i).getX();

            auto val =ennemiesInMap->at(i)->getEnnemy()->getPosition().getX();
            auto val1 =initialPositionsOfEnnemies->at(i).getX();
            if (a>0 && val < val1 ){
                ennemiesInMap->at(i)->getEnnemy()->setPosition(
                        Position(
                                val+1,
                                static_cast<int>(a * (val + 1) + b)
                        )
                );
            }
            else if( a>0 && val > val1){
                ennemiesInMap->at(i)->getEnnemy()->setPosition(
                        Position(
                                val-1,
                                static_cast<int>(a * (val -1) + b)
                        )
                );
            }
            else if (a<0 && val < val1 ){
                ennemiesInMap->at(i)->getEnnemy()->setPosition(
                        Position(
                                val+1,
                                static_cast<int>(a * (val + 1) + b)
                        )
                );
            }else {
                ennemiesInMap->at(i)->getEnnemy()->setPosition(
                        Position(
                                val-1,
                                static_cast<int>(a * (val -1) + b)
                        )
                );
            }
        }
    }
}

bool CarteTexture::playerIsAllowedToAttackBoss(const Position &position, const int &margin) {

    bool a=false;
    int distance;
    for (size_t l = 0; l < ennemiesInMap->size() ; ++l) {
        if (bossTexture){
            distance =(int) sqrt(
                    pow(playerTexture.getPlayer().getPosition().getX()-
                        bossTexture->getBoss()->getPosition().getX()
                            ,2)+
                    pow(playerTexture.getPlayer().getPosition().getY()-
                        bossTexture->getBoss()->getPosition().getY()
                            ,2)
            ) ;
            if (margin > distance){
                a= true;
                break;
            }
        }

    }
    return a;
}

bool CarteTexture::bossIsAllowedToAttackPlayer(const Position &position,const int &margin) {
    bool a=false;
    int distance;
    if (bossTexture){
      distance= (int) sqrt(
              pow(position.getX()-bossTexture->getBoss()->getPosition().getX(),2)+
              pow(position.getY()-bossTexture->getBoss()->getPosition().getY(),2)
              );
      if (margin> distance){
          a=true;
      }
    }
    return a;
}

void CarteTexture::bossAttack(const Position &position) {
    if (bossTexture){
        int l=32;
        if (clips->at(2)->y){ l=-32;}
        if (bossIsAllowedToAttackPlayer(position,
                bossTexture->getBoss()->getMargin_detection())){
            std::cout << "The player is here, so stupid !"<<std::endl;



            for (int i = 0; i <3 ; ++i) {
                auto *h= new HarmingObjects("fire");
                int k=0;
                if(i==1){k=-32;}
                else if(i==2){k=32;}

                h->setPosition(
                        Position(
                                bossTexture->getBoss()->getPosition().getX()+k,
                                bossTexture->getBoss()->getPosition().getY()+l
                                )
                        );
                carte->addHarmingObjectToMap(h);
            }

            if (bossIsAllowedToAttackPlayer(
                    position,
                    bossTexture->getBoss()->getMargin_attack()
                    )){
                std::cout << "I can kill him now !!"<<std::endl;
            }
        }else {
            for (int i = 0; i <3 ; ++i) {
                int k=0;
                if(i==1){k=-32;}
                else if(i==2){k=32;}
                carte->deleteHarmingObjectMap(Position(
                        bossTexture->getBoss()->getPosition().getX() +k,
                        bossTexture->getBoss()->getPosition().getY() + l
                ));
            }
        }
    }
    clips->at(2)=new SDL_Rect({32*(frame%3),0,32,32});
}