
//
// Created by amanda on 27/10/18.
//

#include <fstream>
#include "Classes.h"



Classes::Classes(std::string type) {

    std::ifstream classe("./classes/" + type +".txt");
    std::string line;

    /** Getting the name of Classe **/
    std::getline(classe,line);
    name=line;
    /** Getting Strength **/
    std::getline(classe,line);
    strength=std::stoi(line);
    /** Getting Stamina **/
    std::getline(classe,line);
    stamina=std::stoi(line);
    /** Getting Defense **/
    std::getline(classe,line);
    defense=std::stoi(line);
    /** Getting Dexterity **/
    std::getline(classe,line);
    dexterity=std::stoi(line);
    /** Getting Wisdom **/
    std::getline(classe,line);
    wisdom=std::stoi(line);
    /** Getting WillPower **/
    std::getline(classe,line);
    willpower=std::stoi(line);
    /** Getting Luck **/
    std::getline(classe,line);
    luck=std::stoi(line);


}

Classes::~Classes() {

}



const std::string &Classes::getName() const {
    return name;
}

void Classes::setName(const std::string &name) {
    Classes::name = name;
}
int Classes::getStrength() const {
    return strength;
}

void Classes::setStrength(int strength)  {
    this->strength = strength;
}

int Classes::getStamina() const {
    return stamina;
}

void Classes::setStamina(int stamina)  {
    this->stamina = stamina;
}

int Classes::getDefense() const {
    return defense;
}

void Classes::setDefense(int defense)  {
    this->defense = defense;
}

int Classes::getDexterity() const {
    return dexterity;
}

void Classes::setDexterity(int dexterity) {
    Classes::dexterity = dexterity;
}

int Classes::getWisdom() const {
    return wisdom;
}

void Classes::setWisdom(int wisdom) {
    Classes::wisdom = wisdom;
}

int Classes::getWillpower() const {
    return willpower;
}

void Classes::setWillpower(int willpower) {
    Classes::willpower = willpower;
}

int Classes::getLuck() const {
    return luck;
}

void Classes::setLuck(int luck) {
    this->luck = luck;
}
