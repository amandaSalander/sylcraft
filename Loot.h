//
// Created by amanda on 11/11/18.
//

#ifndef PROJECT_1_LOOT_H
#define PROJECT_1_LOOT_H


#include "Element.h"

class Loot: public Element {
public:
    Loot(): stamina(0),strength(0),luck(0),defense(0){};
    Loot(int str, int sta, int lu, int de): stamina(sta),strength(str),luck(lu),defense(de){}

    int getStrength() const;

    void setStrength(int strength);

    int getStamina() const;

    void setStamina(int stamina);

    int getDefense() const;

    void setDefense(int defense);

    int getLuck() const;

    void setLuck(int luck);

private:
    int strength;
    int stamina;
    int defense;
    int luck;

};


#endif //PROJECT_1_LOOT_H
