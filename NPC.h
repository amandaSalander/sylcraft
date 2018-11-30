//
// Created by amanda on 21/11/18.
//

#ifndef PROJECT_1_NPC_H
#define PROJECT_1_NPC_H


#include <vector>
#include <fstream>
#include "Element.h"
#include "Quest.h"

class NPC: public Element {
private:
    std::vector<std::string> prompts;
    std::string name;
    std::vector<Quest*> *quests;
    std::string id;
public:
    NPC(std::string type);

    const std::vector<std::string> &getPrompts() const;

    void setPrompts(const std::vector<std::string> &prompts);

    const std::string &getName() const;

    void setName(const std::string &name);

    std::vector<Quest *> *getQuests() const;

};


#endif //PROJECT_1_NPC_H
