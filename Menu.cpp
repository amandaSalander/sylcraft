//
// Created by amanda on 12/12/18.
//

#include "Menu.h"

Menu::Menu(const std::string &type) {
    std::ifstream in("game/menu/"+type);
    std::string line;
    if (in.is_open()){
        std::getline(in,line);
        id=std::stoi(line);

        std::getline(in,title);
        std::getline(in,subtitle);

        std::getline(in,line);
        getBackToMenu= std::stoi(line);

        std::getline(in,line);
        gotoMenu=std::stoi(line);

        choices= new std::vector<std::string>();

        while (std::getline(in,line)){
            choices->emplace_back(line);
        }
    }
    in.close();
}

int Menu::getId() const {
    return id;
}

const std::string &Menu::getTitle() const {
    return title;
}

const std::string &Menu::getSubtitle() const {
    return subtitle;
}

std::vector<std::string> *Menu::getChoices() const {
    return choices;
}

int Menu::getGotoMenu() const {
    return gotoMenu;
}

int Menu::getGetBackToMenu() const {
    return getBackToMenu;
}
