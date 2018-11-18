//
// Created by amanda on 18/11/18.
//

#include "PlayerStatTexture.h"


PlayerStatTexture::PlayerStatTexture() {
    playerStatTexture= nullptr;
    player= nullptr;
}

PlayerStatTexture::~PlayerStatTexture() {
    if (playerStatTexture!= nullptr){
        SDL_DestroyTexture(playerStatTexture);
        playerStatTexture= nullptr;
    }
    if (player!= nullptr){
        delete  player;
        player= nullptr;
    }
}

void PlayerStatTexture::render(SDL_Renderer *gRenderer) {

    //Globally used font
    TTF_Font *gFont = nullptr;

    gFont = TTF_OpenFont( "./fonts/november.ttf", 28 );

    if( gFont == nullptr ) {
        std::cout <<"Failed to load lazy font! SDL_ttf Error: "<< TTF_GetError() <<std::endl;
    }
    SDL_Color textColor= {170,160,200,20};
    std::string hi("hello_world");
    SDL_Surface* textSurface;
    textSurface = TTF_RenderText_Solid(gFont,hi.c_str(),textColor);

    SDL_Rect fillRect= {960,0,200,200};
    SDL_RenderFillRect( gRenderer, &fillRect );
    playerStatTexture=SDL_CreateTextureFromSurface( gRenderer, textSurface );
    if (playerStatTexture== nullptr){
        std::cout << "enable to create text texture" << std::endl;
    }
    else {
        std::cout << "created text texture" << std::endl;
    }


}

SDL_Texture *PlayerStatTexture::getPlayerStatTexture() const {
    return playerStatTexture;
}

void PlayerStatTexture::setPlayerStatTexture(SDL_Texture *playerStatTexture) {
    PlayerStatTexture::playerStatTexture = playerStatTexture;
}

Player *PlayerStatTexture::getPlayer() const {
    return player;
}

void PlayerStatTexture::setPlayer(Player *player) {
    PlayerStatTexture::player = player;
}
