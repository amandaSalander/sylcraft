#include <utility>

//
// Created by amanda on 12/12/18.
//

#ifndef PROJECT_1_MENU_H
#define PROJECT_1_MENU_H


#include <vector>
#include <string>
#include <iostream>
#include <fstream>
class Menu {
private:
    int id;
    std::string title;
    std::string subtitle;
    std::vector<std::string> *choices{};
    int gotoMenu;
    int getBackToMenu;

public:
    Menu(int _id,std::string _title, std::string _subtitle,std::vector<std::string> *_choices, int _goto,int _getback):
    id(_id),title(std::move(_title)),subtitle(std::move(_subtitle)),choices(_choices), gotoMenu(_goto),
    getBackToMenu(_getback){};
    Menu(const std::string &type);

    int getId() const;

    const std::string &getTitle() const;

    const std::string &getSubtitle() const;

    std::vector<std::string> *getChoices() const;

    int getGotoMenu() const;

    int getGetBackToMenu() const;
};


#endif //PROJECT_1_MENU_H
