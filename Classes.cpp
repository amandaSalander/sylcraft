
//
// Created by amanda on 27/10/18.
//

#include "Classes.h"

int Classes::classes_number=0;

Classes::~Classes() {
    classes_number--;
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

void Classes::setStrength(int strength) {
    Classes::strength = strength;
}

int Classes::getStamina() const {
    return stamina;
}

void Classes::setStamina(int stamina) {
    Classes::stamina = stamina;
}

int Classes::getDefense() const {
    return defense;
}

void Classes::setDefense(int defense) {
    Classes::defense = defense;
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
    Classes::luck = luck;
}
