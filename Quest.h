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
};


#endif //PROJECT_1_QUEST_H
