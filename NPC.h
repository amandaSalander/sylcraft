//
// Created by amanda on 21/11/18.
//

#ifndef PROJECT_1_NPC_H
#define PROJECT_1_NPC_H


#include <vector>
#include <fstream>
#include "Element.h"

class NPC: public Element {
private:
    std::vector<std::string> prompts;
    std::string name;
public:
    NPC(std::string type);

};


#endif //PROJECT_1_NPC_H
