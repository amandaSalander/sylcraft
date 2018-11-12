//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_ELEMENT_H
#define PROJECT_1_ELEMENT_H


#include "Position.h"

class Element {

private: Position position;

public:
    Element(){};
    Element(const Position &pos): position(pos){};
    const Position &getPosition() const;
    void setPosition(const Position &pos);


};


#endif //PROJECT_1_ELEMENT_H
