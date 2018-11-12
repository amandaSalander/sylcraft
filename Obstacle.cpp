//
// Created by amanda on 27/10/18.
//

#include "Obstacle.h"

const std::string &Obstacle::getType() const {
    return type;
}

void Obstacle::setType(const std::string &type) {
    Obstacle::type = type;
}
