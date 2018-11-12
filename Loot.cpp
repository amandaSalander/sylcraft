//
// Created by amanda on 11/11/18.
//

#include "Loot.h"

int Loot::getStrength() const {
    return strength;
}

void Loot::setStrength(int strength) {
    Loot::strength = strength;
}

int Loot::getStamina() const {
    return stamina;
}

void Loot::setStamina(int stamina) {
    Loot::stamina = stamina;
}

int Loot::getDefense() const {
    return defense;
}

void Loot::setDefense(int defense) {
    Loot::defense = defense;
}

int Loot::getLuck() const {
    return luck;
}

void Loot::setLuck(int luck) {
    Loot::luck = luck;
}
