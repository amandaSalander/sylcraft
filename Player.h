//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_PLAYER_H
#define PROJECT_1_PLAYER_H

#include <string>
#include <iostream>
#include "Classes.h"
#include "Element.h"

class Player : public Element {
private:
    std::string name;
    std::string team;
    Classes classe;
public:static int players_number;

public:
    Player();
    Player(std::string na,std::string te,Classes cl,Position po);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getTeam() const;

    void setTeam(const std::string &team);

    const Classes &getClasse() const;

    void setClasse(const Classes &classe);

    static int getPlayers_number();

    static void setPlayers_number(int players_number);

    ~Player() override;

};


#endif //PROJECT_1_PLAYER_H
