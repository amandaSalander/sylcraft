//
// Created by amanda on 21/11/18.
//


#include "HarmingObjects.h"


HarmingObjects::HarmingObjects(const std::string &type) {
    std::ifstream file("harming_objects/" + type +".txt");
    std::string line;

    /** get Path of the loot image to display the corresponding image to each loot**/
    std::getline(file,line);
    setType(line);


    /** Get the strength that the player can acquire with the loot**/
    std::getline(file,line);
    strength= std::stoi(line);

    /** Get the stamina that the player can acquire with the loot**/
    std::getline(file,line);
    stamina= std::stoi(line);

    /** Get the defense that the player can acquire with the loot**/
    std::getline(file,line);
    defense= std::stoi(line);

    /** Get the luck that the player can acquire with the loot**/
    std::getline(file,line);
    luck= std::stoi(line);

    file.close();
}

int HarmingObjects::getStrength() const {
    return strength;
}

int HarmingObjects::getStamina() const {
    return stamina;
}

int HarmingObjects::getDefense() const {
    return defense;
}

int HarmingObjects::getLuck() const {
    return luck;
}
