//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_OBSTACLE_H
#define PROJECT_1_OBSTACLE_H

#include <string>

#include "Element.h"

class Obstacle : virtual public Element{
public:
    const std::string &getType() const;

    void setType(const std::string &type);

private:
    std::string type;
};


#endif //PROJECT_1_OBSTACLE_H
