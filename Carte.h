//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_CARTE_H
#define PROJECT_1_CARTE_H


#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include "Element.h"
#include "Player.h"
#include "Loot.h"
#include "Obstacle.h"
#include "Item.h"
#include "NPC.h"

#include <SDL2/SDL.h>
#include <algorithm>

struct item_t
{
    unsigned short quest_id;
    unsigned short npc_id;
    unsigned short item_id;
};

class Carte {

private:
    int largeur; // en pixel
    int hauteur; // en pixel
    std::vector<std::vector<Element*>>* layers;
    std::vector<Item*> *itemsInMap;
    std::vector<NPC*> *npcs;

public:

    Carte(std::string filename);

    std::vector<std::vector<Element *>>* getLayers() const;

    void addPlayerToMap(Player* player,int position);

    bool allowedMovement(SDL_Keycode key,Position position);

    void updatePosition(Position position,int indexPlayer);

    Position const allowedPick(Position position);

    const Loot deleteLoot(const Position &position);


    void updatePlayerStat(const Player &player, int indexPlayer );

    bool addLootToMap(Loot *loot);

    bool addObstacleToMap(Obstacle *obstacle);

    Position const isHarming(const Position &position,float &timestep,float &start);

    Position const allowedTalkToNPC(Position position);

    /** margin can only be a multiplier of 32, e.g. 32,64,96,....  **/
    bool playerIsAllowedToAttack(const Position &position,const int &margin=32);

    item_t* allowedToPickItem(const Position &position,const int &margin=32);

    std::string* pickItem(const Position &position,const int &margin=32);



};


#endif //PROJECT_1_CARTE_H
