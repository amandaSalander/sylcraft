//
// Created by amanda on 30/11/18.
//

#ifndef PROJECT_1_QUEST_H
#define PROJECT_1_QUEST_H

#include <fstream>
#include <string>
#include <vector>
#include "Item.h"
#include "Loot.h"


enum QUEST_STATE {
    QUEST_NOT_STARTED,
    QUEST_ACCEPTED,
    QUEST_COMPLETED,
    QUEST_ONGOING
};

class Quest {
private:
    unsigned short npc_id;
    unsigned short id;
    std::string title;
    std::vector<Item*> *items;
    QUEST_STATE quest_state;
    /** Explanation of the quest and the why of the quest  **/
    std::vector<std::string> *talks;
    std::vector<Loot*> *gifts;
public:
    Quest(std::string type);
    ~Quest();

    std::vector<Item *> *getItems() const;

    const std::string &getTitle() const;

    std::vector<std::string> *getTalks() const;

    unsigned short getId() const;

    QUEST_STATE getQuest_state() const;

    void setQuest_state(QUEST_STATE quest_state);

    std::vector<Loot *> *getGifts() const;
};


#endif //PROJECT_1_QUEST_H
