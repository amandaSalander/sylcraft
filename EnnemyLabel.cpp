//
// Created by amanda on 24/11/18.
//

#include "EnnemyLabel.h"
#include "ElementTexture.h"


void EnnemyLabel::render(const Position &position, SDL_Renderer *gRenderer) {
    TTF_Font *gFont = nullptr;
    TTF_Init();
    gFont = TTF_OpenFont( "fonts/RifficFree-Bold.ttf",11);
    TextTexture textTexture;

    ElementTexture elementTexture;

    SDL_Rect fillRect= {position.getX()-16,position.getY()-6,64,5};

    SDL_SetRenderDrawColor( gRenderer, 201,145,87,0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    fillRect= {position.getX()-16,position.getY()-6,(int)(64* (stamina*1.0/maxStamina)),5};

    SDL_SetRenderDrawColor( gRenderer, 220,20,60,0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    elementTexture.loadImageFromFile("assets/tiles/attack.png",gRenderer);

    elementTexture.render(position.getX()-16,position.getY(), nullptr,gRenderer);

    elementTexture.loadImageFromFile("assets/tiles/box.png",gRenderer);

    elementTexture.render(position.getX(),position.getY(), nullptr,gRenderer);

    elementTexture.loadImageFromFile("assets/tiles/defense.png",gRenderer);

    elementTexture.render(position.getX()+16,position.getY(), nullptr,gRenderer);

    elementTexture.loadImageFromFile("assets/tiles/box.png",gRenderer);

    elementTexture.render(position.getX()+32,position.getY(), nullptr,gRenderer);




    SDL_Color textColor= {220,220,220};

    if( !textTexture.loadFromRenderedText(std::to_string(attackPower), textColor,gRenderer,gFont ) )
    {
        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
    }
    else {
        textTexture.render(position.getX()+2,position.getY()+1, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
    }

    if( !textTexture.loadFromRenderedText(std::to_string(defensePower), textColor,gRenderer,gFont ) )
    {
        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
    }
    else {
        textTexture.render(position.getX()+34,position.getY()+1, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
    }


    TTF_CloseFont(gFont);

}