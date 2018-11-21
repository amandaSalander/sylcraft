//
// Created by amanda on 04/11/18.
//

#ifndef PROJECT_1_CARTETEXTURE_H
#define PROJECT_1_CARTETEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Carte.h"
#include "PlayerTexture.h"
#include "LootTexture.h"

class CarteTexture {
private:

    Carte *carte;
    PlayerTexture playerTexture;
    SDL_Rect sdl_rect;
    std::vector<PlayerTexture*> playerInMap;
    std::vector<LootTexture*> lootInMap;
    int playerIndex;
    bool changedPlayer;

public:
    CarteTexture();

    virtual  ~CarteTexture();


    void render(SDL_Renderer *gRenderer);


    void changeCurrentRender(SDL_Keycode key,float &timestep,float &start);


    Carte *getCarte();

    void setCarte(Carte *carte);

    /** This method is to pick up a loot if it's possible to do so.**/
    void PickUpLoot(SDL_Keycode key);


    void updateCurrentPlayer(SDL_Keycode key);


};


#endif //PROJECT_1_CARTETEXTURE_H
