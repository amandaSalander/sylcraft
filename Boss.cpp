//
// Created by amanda on 12/12/18.
//

#include "Boss.h"

Boss::Boss(const std::string &type) {
    std::ifstream in("boss/"+type+".txt");
    std::string line;
    if (in.is_open()){
        /** get the boss name **/
        std::getline(in,line);
        name=line;

        /** get the sprite of the boss **/
        std::getline(in,line);
        setType(line);

        /** get the boss max stamina**/
        std::getline(in,line);
        max_stamina=std::stoi(line);

        /** get the boss stamina**/
        std::getline(in,line);
        stamina=std::stoi(line);


        /** get the boss attack strength **/
        std::getline(in,line);
        attack_strength=std::stoi(line);

        /** get the boss defense strength **/
        std::getline(in,line);
        defense_strength=std::stoi(line);

        /** get the boss margin detection **/
        std::getline(in,line);
        margin_detection=std::stoi(line);

        /** get the boss margin attack **/
        std::getline(in,line);
        margin_attack=std::stoi(line);

        /** get the boss harming objects**/
        std::getline(in,line);
        harming_objects= new std::vector<std::string>();
        harming_objects->emplace_back(line);


        /** get the boss obsctales objects**/
        std::getline(in,line);
        obstacles= new std::vector<std::string>();
        obstacles->emplace_back(line);

        /** get the boss talk **/
        prompts= new std::vector<std::string>();
        while(std::getline(in,line)){
            prompts->emplace_back(line);
        }
    }

    in.close();
}

const std::string &Boss::getName() const {
    return name;
}

int Boss::getStamina() const {
    return stamina;
}

int Boss::getMax_stamina() const {
    return max_stamina;
}

int Boss::getAttack_strength() const {
    return attack_strength;
}

int Boss::getDefense_strength() const {
    return defense_strength;
}

int Boss::getMargin_detection() const {
    return margin_detection;
}

int Boss::getMargin_attack() const {
    return margin_attack;
}

std::vector<std::string> *Boss::getHarming_objects() const {
    return harming_objects;
}

std::vector<std::string> *Boss::getObstacles() const {
    return obstacles;
}

std::vector<std::string> *Boss::getPrompts() const {
    return prompts;
}
