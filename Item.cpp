//
// Created by amanda on 27/10/18.
//


#include "Item.h"


Item::Item(std::string type) {
    std::ifstream item("items/" + type +".txt");
    std::string line;

    /** get the npc_id of the item**/
    std::getline(item,line);
    npc_id=(unsigned short)std::stoi(line);

    /** get the quest_id of the item**/
    std::getline(item,line);
    quest_id=(unsigned short )std::stoi(line);

    /** get the quest_id of the item**/
    std::getline(item,line);
    item_id=(unsigned short )std::stoi(line);

    /** get the name of the item**/
    std::getline(item,line);
    name=line;

    /** get the typeof the item**/
    std::getline(item,line);
    setType(line);

    /** get the state found or not the item**/
    std::getline(item,line);
    found=(bool)std::stoi(line);

    /** get the position X Y**/
    std::getline(item,line);
    int _x=std::stoi(line);
    std::getline(item,line);
    int _y=std::stoi(line);
    setPosition(Position(_x,_y));
}

unsigned short Item::getQuest_id() const {
    return quest_id;
}

unsigned short Item::getNpc_id() const {
    return npc_id;
}

void Item::setFound(bool found) {
    Item::found = found;
}

bool Item::isFound() const {
    return found;
}

const std::string &Item::getName() const {
    return name;
}

unsigned short Item::getItem_id() const {
    return item_id;
}
