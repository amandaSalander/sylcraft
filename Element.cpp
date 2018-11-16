
//
// Created by amanda on 27/10/18.
//

#include "Element.h"


const Position &Element::getPosition() const{
    return position;
}

void Element::setPosition(const Position &pos) {
    this->position = pos;
}

const std::string &Element::getType() const {
    return type;
}

void Element::setType(const std::string &type) {
    Element::type = type;
}
