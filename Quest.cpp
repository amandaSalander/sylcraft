//
// Created by amanda on 30/11/18.
//

#include "Quest.h"


Quest::Quest(std::string type) {

    std::ifstream quest("quests/" + type +".txt");
    std::string line;

    /** Get npc_id of the quest**/
    std::getline(quest,line);
    npc_id= (unsigned short)std::stoi(line);

    /** Get id of the quest**/
    std::getline(quest,line);
    id= (unsigned short)std::stoi(line);

    /** Get title of the quest**/
    std::getline(quest,line);
    title= line;

    /** Get the items of the quest **/
    items=new std::vector<Item*>();
    std::getline(quest,line);
    items->emplace_back(new Item(line));

    /** Get the loots of the quest **/
    gifts=new std::vector<Loot*>();
    std::getline(quest,line);
    std::vector<std::string> list;

    gifts->emplace_back(new Loot(line));

    /** Get the state of the quest **/
    std::getline(quest,line);

    switch (std::stoi(line)){
        case 1:
            quest_state= QUEST_ACCEPTED;
            break;
        case 2:
            quest_state=QUEST_COMPLETED;
            break;
        case 3:
            quest_state=QUEST_ONGOING;
            break;
        default:
            quest_state= QUEST_NOT_STARTED;
            break;
    }

    /** Get the talks for the quest **/
    talks= new std::vector<std::string>();
    while (std::getline(quest,line)){
        talks->emplace_back(line);
    }

    quest.close();
}

Quest::~Quest() {
    delete  items;
    items= nullptr;
    delete gifts;
    gifts= nullptr;
    delete talks;
    talks= nullptr;
}

std::vector<Item *> *Quest::getItems() const {
    return items;
}

const std::string &Quest::getTitle() const {
    return title;
}

std::vector<std::string> *Quest::getTalks() const {
    return talks;
}

unsigned short Quest::getId() const {
    return id;
}
