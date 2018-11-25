//
// Created by amanda on 24/11/18.
//


#include "PlayerLabel.h"
#include "ElementTexture.h"


void PlayerLabel::render(const Position &position, SDL_Renderer *gRenderer) {



    TTF_Font *gFont = nullptr;
    TTF_Init();
    gFont = TTF_OpenFont( "fonts/RifficFree-Bold.ttf",11);
    TextTexture textTexture;

    ElementTexture elementTexture;
    if (isCurrentPlayer){
        elementTexture.loadImageFromFile("assets/tiles/icon_1.png",gRenderer);
    }else{elementTexture.loadImageFromFile("assets/tiles/icon.png",gRenderer);}

    elementTexture.render(position.getX(),position.getY(), nullptr,gRenderer);

    SDL_Color textColor= {50,50,50};

    if( !textTexture.loadFromRenderedText( playerName, textColor,gRenderer,gFont ) )
    {
        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
    }
    else {
        textTexture.render(position.getX()- (playerName.size()-4)*3,position.getY()-10, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
    }
    if( !textTexture.loadFromRenderedText(std::to_string(playerNumber), textColor,gRenderer,gFont ) )
    {
        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
    }
    else {
        textTexture.render(position.getX()+9,position.getY()+5, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
    }



    TTF_CloseFont(gFont);

}
