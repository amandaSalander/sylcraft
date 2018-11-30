#include <utility>

//
// Created by amanda on 27/10/18.
//

#include "Player.h"
#include <string>
#include <iostream>
#include "Classes.h"



Player::Player() {

}

Player::Player(std::string na,std::string te,Classes *cl,Position po): name(std::move(na)),team(std::move(te)),classe(cl) {
    inventory= new std::vector<Item*>();
}


const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

const std::string &Player::getTeam() const {
    return team;
}

void Player::setTeam(const std::string &team) {
    Player::team = team;
}





Classes *Player::getClasse() const {
    return classe;
}

void Player::setClasse(Classes *classe) {
    Player::classe = classe;
}

bool Player::addToIventory(Item *item) {
    if (inventory->size()<max_item){
        inventory->emplace_back(item);
        return true;
    }
    else {
        return  false;
    }
}

std::vector<Item *> *Player::getInventory() const {
    return inventory;
}
