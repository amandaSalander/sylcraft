//
// Created by amanda on 21/11/18.
//

#ifndef PROJECT_1_HARMINGOBJECTS_H
#define PROJECT_1_HARMINGOBJECTS_H

#include <fstream>
#include "Element.h"

class HarmingObjects: public Element {
private:
    int strength;
    int stamina;
    int defense;
    int luck;
public :
    HarmingObjects(const std::string &type);

    int getStrength() const;

    int getStamina() const;

    int getDefense() const;

    int getLuck() const;
};


#endif //PROJECT_1_HARMINGOBJECTS_H
