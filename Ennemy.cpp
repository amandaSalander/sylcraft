//
// Created by amanda on 22/11/18.
//


#include "Ennemy.h"


Ennemy::Ennemy(const std::string &type) {
    std::ifstream file("ennemies/" + type +".txt");
    std::string line;

    std::getline(file,line);
    setType(line);

    std::getline(file,line);
    stamina=std::stoi(line);

    std::getline(file,line);
    attackEffect=std::stoi(line);

    std::getline(file,line);
    defenseEffect=std::stoi(line);

    std::getline(file,line);
    max_stamina=std::stoi(line);

    std::getline(file,line);
    margin_detection=std::stoi(line);

    std::getline(file,line);
    margin_attack=std::stoi(line);

    file.close();
}

int Ennemy::getStamina() const {
    return stamina;
}

int Ennemy::getAttackEffect() const {
    return attackEffect;
}

int Ennemy::getDefenseEffect() const {
    return defenseEffect;
}

int Ennemy::getMax_stamina() const {
    return max_stamina;
}


void Ennemy::setStamina(int stamina) {
    Ennemy::stamina = stamina;
}

void Ennemy::setAttackEffect(int attackEffect) {
    Ennemy::attackEffect = attackEffect;
}

int Ennemy::getMargin_detection() const {
    return margin_detection;
}

int Ennemy::getMargin_attack() const {
    return margin_attack;
}
