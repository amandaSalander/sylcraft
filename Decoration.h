//
// Created by amanda on 11/11/18.
//

#ifndef PROJECT_1_DECORATION_H
#define PROJECT_1_DECORATION_H

#include <string>
#include "Element.h"

class Decoration: public Element {
public:
    const std::string &getType() const;

    void setType(const std::string &type);

private:
    std::string type;
};


#endif //PROJECT_1_DECORATION_H
