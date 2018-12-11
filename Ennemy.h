//
// Created by amanda on 22/11/18.
//

#ifndef PROJECT_1_ENNEMY_H
#define PROJECT_1_ENNEMY_H

#include <fstream>
#include "Element.h"

class Ennemy : public Element{
private:
    int stamina;
    int attackEffect;
    int defenseEffect;
    int max_stamina;

public:
    Ennemy(std::string type);

    int getStamina() const;

    int getAttackEffect() const;

    int getDefenseEffect() const;

    int getMax_stamina() const;

    void setStamina(int stamina);

    void setAttackEffect(int attackEffect);
};


#endif //PROJECT_1_ENNEMY_H
