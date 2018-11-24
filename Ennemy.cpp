//
// Created by amanda on 22/11/18.
//


#include "Ennemy.h"


Ennemy::Ennemy(std::string type) {
    std::ifstream file("ennemies/" + type +".txt");
    std::string line;

    std::getline(file,line);
    setType(line);

    std::getline(file,line);
    stamina=std::stoi(line);

    std::getline(file,line);
    attackEffect=std::stoi(line);

}


