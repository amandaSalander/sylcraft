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

    std::vector<std::vector<Element*>> layers;
public:
    Carte():largeur(0),hauteur(0){};

    // THIS METHOD IS TO TEST A NEW FEATURE WHICH IS RENDERING CARTE BY LAYERS, THE LAST LAYERS CONTAIN ONLY OBSTACLE OBJECTS
    Carte(std::string filename);


    const std::vector<std::vector<Element *>> &getLayers() const;


    void addPlayerToMap(Player* player,int position);

    bool allowedMovement(SDL_Keycode key,Position position);

    void updatePosition(Position position,int indexPlayer);


};


#endif //PROJECT_1_CARTE_H
