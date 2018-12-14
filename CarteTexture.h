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
#include "LootTexture.h"
#include "BubbleTalk.h"
#include "NPC.h"
#include "EnnemyTexture.h"
#include "BossTexture.h"
#include <math.h>



class CarteTexture {
private:

    Carte *carte;
    PlayerTexture playerTexture;
    std::vector<SDL_Rect*> *clips;
    std::vector<PlayerTexture*> *playerInMap;
    std::vector<LootTexture*> lootInMap;
    std::vector<EnnemyTexture*> *ennemiesInMap;
    int playerIndex;
    bool changedPlayer;
    BubbleTalk *currentBubble;
    int displayQuest;
    NPC *currentNPC;
    size_t indexBubble;
    std::vector<Position> *initialPositionsOfEnnemies;
    bool switched;
    int frame;
    bool renderCurrentPlayer;
    int currentEnnemy;
    int numberOfEnnemies;
    EnnemyTexture *ennemyInMovement;
    int indexEnnemyInMovement;
    BossTexture *bossTexture;
    Position *bossInitialPoisition;
    bool firstRender;


public:
    CarteTexture();

    virtual  ~CarteTexture();


    void render(SDL_Renderer *gRenderer);


    void changeCurrentRender(SDL_Keycode key,float &timestep,float &start);


    Carte *getCarte();

    void setCarte(Carte *carte);

    /** This method is to pick up a loot if it's possible to do so.**/
    void PickUpLoot(SDL_Keycode key);


    void updateCurrentPlayer(SDL_Keycode key);

    int playerIsAllowedToAttack(const Position &position, const int &margin=48);

    bool ennemyIsAllowedToAttack(const size_t &k, const int &margin=48);

    void ennemyAttack(const size_t &k);

    /** when a player in the map has a stamina equal to zero deleted it from the playerInMap **/
    void updatePlayersInMap();

    /****/
    void updateEnnemiesInMap();
    void playerAttack();

    /** if an ennemy has moved from it initial place to attack a player, if the player is out of range
     * the ennemy must come back to it's original place and get back to its random movement**/
    void resetEnnemyPosition();

    bool playerIsAllowedToAttackBoss(const Position &position, const int &margin=48);

    bool bossIsAllowedToAttackPlayer(const Position &position, const int &margin=48);

    void bossAttack(const Position &position);

    void playerAttackBoss();
};


#endif //PROJECT_1_CARTETEXTURE_H
