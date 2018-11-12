//
// Created by amanda on 11/11/18.
//

#include "Decoration.h"

const std::string &Decoration::getType() const {
    return type;
}

void Decoration::setType(const std::string &type) {
    Decoration::type = type;
}
