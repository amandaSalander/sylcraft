//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_ELEMENT_H
#define PROJECT_1_ELEMENT_H


#include "Position.h"
#include <string>

class Element {

private: Position position;
         std::string type;
public:
    Element() = default;;

    virtual  ~Element() = default;

    const Position &getPosition()const;
    void setPosition(const Position &pos);

    const std::string &getType() const;

    void setType(const std::string &type);


};


#endif //PROJECT_1_ELEMENT_H
