//
// Created by amanda on 27/10/18.
//

#include "Player.h"
#include <string>
#include <iostream>
#include "Classes.h"

int Player::players_number=0;

Player::Player() {
    players_number++;
}

Player::Player(std::string na,std::string te,Classes cl,Position po): name(na),team(te),classe(cl) {
    players_number++;
//    setPosition(po);
}

Player::~Player() {
    players_number--;
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

const Classes &Player::getClasse() const {
    return classe;
}

void Player::setClasse(const Classes &classe) {
    Player::classe = classe;
}

int Player::getPlayers_number() {
    return players_number;
}

void Player::setPlayers_number(int players_number) {
    Player::players_number = players_number;
}
