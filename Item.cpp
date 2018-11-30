//
// Created by amanda on 27/10/18.
//


#include "Item.h"


Item::Item(std::string type) {
    std::ifstream item("items/" + type +".txt");
    std::string line;
    /** get the name of the item**/
    std::getline(item,line);
    name=line;

    /** get the typeof the item**/
    std::getline(item,line);
    setType(line);

    /** get the position X Y**/
    std::getline(item,line);
    int _x=std::stoi(line);
    std::getline(item,line);
    int _y=std::stoi(line);
    setPosition(Position(_x,_y));
}