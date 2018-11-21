//
// Created by amanda on 21/11/18.
//


#include "NPC.h"

NPC::NPC(std::string type) {
    std::ifstream file("NPC/" + type +".txt");
    std::string line;

    /** get  name **/
    std::getline(file,line);
    name=line;

    std::getline(file,line);
    setType(line);

    while (getline(file,line)){
        prompts.emplace_back(line);
    }
}