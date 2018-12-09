//
// Created by amanda on 21/11/18.
//


#include <sstream>
#include "NPC.h"

NPC::NPC(std::string type) {
    std::ifstream file("NPC/" + type +".txt");
    std::string line;

    /** get  name **/
    std::getline(file,line);
    npc_id=(unsigned short)std::stoi(line);


    /** get  name **/
    std::getline(file,line);
    name=line;

    std::getline(file,line);
    setType(line);

    /** get quest**/

    std::getline(file,line);

    if (line!="null"){
        quests= new std::vector<Quest*>();
        std::stringstream ss(line);
        std::string item;
        char delimeter=',';
        while (std::getline(ss, item, delimeter))
        {
            quests->emplace_back( new Quest(item));
        }



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

unsigned short NPC::getNpc_id() const {
    return npc_id;
}
