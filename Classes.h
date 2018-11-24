//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_CLASSES_H
#define PROJECT_1_CLASSES_H

#include <string>
#include <iostream>

class Classes {
//public:
//    static int classes_number;
private: int strength;
         int stamina;
         int defense;
         int dexterity;
         int wisdom;
         int willpower;
         int luck;
         std::string name;


public:
    Classes():strength(0),stamina(0),defense(0),dexterity(0),wisdom(0),willpower(0),luck(0),name(""){};

    Classes(std::string type);

    int attackPower(const int &_luck);
    int defensePower();


    int getStrength() const;

    void setStrength(int strength);

    int getStamina() const;

    void setStamina(int stamina);

    int getDefense() const;

    void setDefense(int defense);

    int getDexterity() const;

    void setDexterity(int dexterity);

    int getWisdom() const;

    void setWisdom(int wisdom);

    int getWillpower() const;

    void setWillpower(int willpower);

    int getLuck() const;

    void setLuck(int luck);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual ~Classes();;
};


#endif //PROJECT_1_CLASSES_H
