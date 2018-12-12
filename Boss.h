//
// Created by amanda on 12/12/18.
//

#ifndef PROJECT_1_BOSS_H
#define PROJECT_1_BOSS_H


#include <vector>
#include <fstream>
#include "Element.h"

class Boss: public Element {
private:
    std::string name;
    int stamina;
    int max_stamina;
    int attack_strength;
    int defense_strength;
    int margin_detection;
    int margin_attack;
    /** boss can throw/add harming objects to map **/
    std::vector<std::string> *harming_objects;
    /** boss can throw or add obstacle to map **/
    std::vector<std::string> *obstacles;
    /** conversation **/
    std::vector<std::string> *prompts;
public:
    Boss(const std::string &type);

    const std::string &getName() const;

    int getStamina() const;

    int getMax_stamina() const;

    int getAttack_strength() const;

    int getDefense_strength() const;

    int getMargin_detection() const;

    int getMargin_attack() const;

    std::vector<std::string> *getHarming_objects() const;

    std::vector<std::string> *getObstacles() const;

    std::vector<std::string> *getPrompts() const;
};


#endif //PROJECT_1_BOSS_H
