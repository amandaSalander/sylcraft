//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_ITEM_H
#define PROJECT_1_ITEM_H

#include <string>
#include <iostream>
#include "Element.h"
#include <fstream>

class Item : public Element {
private:
    unsigned short quest_id;
    unsigned short npc_id;
    unsigned short item_id;
    bool found;
    std::string name;
public:
    Item(std::string path);

    unsigned short getQuest_id() const;

    unsigned short getNpc_id() const;

    void setFound(bool found);

    bool isFound() const;

    const std::string &getName() const;

    unsigned short getItem_id() const;
};


#endif //PROJECT_1_ITEM_H
