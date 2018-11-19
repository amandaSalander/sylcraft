//
// Created by amanda on 11/11/18.
//


#include "Loot.h"

Loot::Loot(std::string type) {
    std::ifstream loot("./loots/" + type +".txt");
    std::string line;

    /** get Path of the loot image to display the corresponding image to each loot**/
    std::getline(loot,line);
    setType(line);


    /** Get the strength that the player can acquire with the loot**/
    std::getline(loot,line);
    strength= std::stoi(line);

    /** Get the stamina that the player can acquire with the loot**/
    std::getline(loot,line);
    stamina= std::stoi(line);

    /** Get the defense that the player can acquire with the loot**/
    std::getline(loot,line);
    defense= std::stoi(line);

    /** Get the luck that the player can acquire with the loot**/
    std::getline(loot,line);
    luck= std::stoi(line);

}

int Loot::getStrength() const {
    return strength;
}
//
//void Loot::setStrength(int strength) {
//    Loot::strength = strength;
//}
//
int Loot::getStamina() const {
    return stamina;
}
//
//void Loot::setStamina(int stamina) {
//    Loot::stamina = stamina;
//}
//
int Loot::getDefense() const {
    return defense;
}
//
//void Loot::setDefense(int defense) {
//    Loot::defense = defense;
//}
//
int Loot::getLuck() const {
    return luck;
}
////
//void Loot::setLuck(int luck) {
//    Loot::luck = luck;
//}
