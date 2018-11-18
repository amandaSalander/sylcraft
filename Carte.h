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
#include "Player.h"

#include <SDL2/SDL.h>


class Carte {

private:
    int largeur; // en pixel
    int hauteur; //en pixel
    std::vector<Element*>  carte;
    std::vector<std::vector<Element*>> layers;
public:
    Carte():largeur(0),hauteur(0){};
    Carte(int l,int h):largeur(l),hauteur(h){}
    Carte(std::string filename);

    // THIS METHOD IS TO TEST A NEW FEATURE WHICH IS RENDERING CARTE BY LAYERS, THE LAST LAYERS CONTAIN ONLY OBSTACLE OBJECTS
    Carte(std::string filename,int);



    int getLargeur() const;

    void setLargeur(int largeur);

    int getHauteur() const;

    void setHauteur(int hauteur);

    std::vector<Element*> &getCarte();

    void setCarte(const std::vector<Element> &carte);

    const std::vector<std::vector<Element *>> &getLayers() const;

    void setLayers(const std::vector<std::vector<Element *>> &layers);;

    void addPlayerToMap(Player* player,int position);

    bool allowedMovement(SDL_Keycode key,Position position);

    void updatePosition(Position position,int indexPlayer);

    void updateCurrentPlayer();
};


#endif //PROJECT_1_CARTE_H
