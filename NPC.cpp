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

    /** get quest**/

    std::getline(file,line);

    if (line!="null"){
        quests= new std::vector<Quest*>();
        quests->emplace_back( new Quest(line));


    }
    else {
        quests= nullptr;
    }
    while (getline(file,line)){
        prompts.emplace_back(line);
    }

}

const std::vector<std::string> &NPC::getPrompts() const {
    return prompts;
}

void NPC::setPrompts(const std::vector<std::string> &prompts) {
    NPC::prompts = prompts;
}

const std::string &NPC::getName() const {
    return name;
}

void NPC::setName(const std::string &name) {
    NPC::name = name;
}

std::vector<Quest *> *NPC::getQuests() const {
    return quests;
}
