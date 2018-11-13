//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_CARTE_H
#define PROJECT_1_CARTE_H


#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include "Element.h"


class Carte {

private:
    int largeur; // en pixel
    int hauteur; //en pixel
    std::vector<Element*>  carte;
public:
    Carte():largeur(0),hauteur(0){};
    Carte(int l,int h):largeur(l),hauteur(h){}
    Carte(std::string filename);

    int getLargeur() const;

    void setLargeur(int largeur);

    int getHauteur() const;

    void setHauteur(int hauteur);

    std::vector<Element*> &getCarte();

    void setCarte(const std::vector<Element> &carte);;
};


#endif //PROJECT_1_CARTE_H
