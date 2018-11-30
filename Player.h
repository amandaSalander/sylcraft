//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_PLAYER_H
#define PROJECT_1_PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "Classes.h"
#include "Element.h"
#include "Item.h"

const int max_item=4;

class Player : public Element {
private:
    std::string name;
    std::string team;
    Classes *classe;
    std::vector<Item*> *inventory;



public:
    Player();
    Player(std::string na,std::string te,Classes *cl,Position po);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getTeam() const;

    void setTeam(const std::string &team);


    Classes *getClasse() const;

    void setClasse(Classes *classe);

    bool addToIventory(Item *item);

    std::vector<Item *> *getInventory() const;

};


#endif //PROJECT_1_PLAYER_H
