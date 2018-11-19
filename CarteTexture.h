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

class CarteTexture {
private:

    Carte carte;
    PlayerTexture playerTexture;
    SDL_Rect sdl_rect;
    std::vector<PlayerTexture*> playerInMap;
    int playerIndex;
    bool changedPlayer;

public:
    CarteTexture();

    virtual  ~CarteTexture();




    void render(SDL_Renderer *gRenderer);


    void changeCurrentRender(SDL_Keycode key);



//    void setCHeight(int cHeight);

    Carte &getCarte();

    void setCarte(const Carte &carte);






//    SDL_Rect &getSdl_rect();


    void updateCurrentPlayer(SDL_Keycode key);



//    const std::vector<PlayerTexture *> &getPlayerInMap() const;

//    void setPlayerInMap(const std::vector<PlayerTexture *> &playerInMap);
};


#endif //PROJECT_1_CARTETEXTURE_H
