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

public:
    Ennemy(std::string type);
};


#endif //PROJECT_1_ENNEMY_H
