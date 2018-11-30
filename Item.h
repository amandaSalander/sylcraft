//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_ITEM_H
#define PROJECT_1_ITEM_H

#include <string>
#include <iostream>
#include "Element.h"
#include <fstream>

class Item : public Element {
private:
    std::string name;
public:
    Item(std::string path);
};


#endif //PROJECT_1_ITEM_H
