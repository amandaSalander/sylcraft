//
// Created by amanda on 04/11/18.
//

#ifndef PROJECT_1_PLAYERTEXTURE_H
#define PROJECT_1_PLAYERTEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Player.h"
#include "ElementTexture.h"

class PlayerTexture: public ElementTexture {

public:
//    PlayerTexture();

//    ~PlayerTexture() override;

//    bool loadImageFromFile(std::string path,SDL_Renderer* gRenderer) override;

//    void free() override;

    //Renders texture at given point

//    void render( int x, int y, SDL_Rect* clip = nullptr,SDL_Renderer* gRenderer= nullptr );

    //Gets image dimensions

    void changeCurrentRender(SDL_Rect *playerRectangle,SDL_Keycode key);

    Player &getPlayer();

    void setPlayer(const Player &player);


private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    //Image dimensions
    int mWidth;
    int mHeight;
    Player player;

};


#endif //PROJECT_1_PLAYERTEXTURE_H
