//
// Created by amanda on 21/11/18.
//


#include "BubbleTalk.h"


BubbleTalk::BubbleTalk(Position *position) {
    this->position=position;
}


void BubbleTalk::render(std::string title,std::string text, SDL_Renderer *gRenderer) {
    TTF_Font *gFont = nullptr;
    TTF_Init();
    gFont = TTF_OpenFont( "/home/amanda/CLionProjects/Project_1/fonts/neuropol x rg.ttf",10);
    TextTexture textTexture;

    if( gFont == nullptr ) {
        std::cout <<"Failed to load lazy font! SDL_ttf Error: "<< TTF_GetError() <<std::endl;
    }

    SDL_Color textColor= {50,50,50};

    SDL_Rect fillRect= {position->getX(),position->getY(),200,40};

    SDL_SetRenderDrawColor( gRenderer, 201,145,87,0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    fillRect.y+=1;
    fillRect.x+=1;
    fillRect.h-=2;
    fillRect.w-=2;


    SDL_SetRenderDrawColor( gRenderer, 225,173,109, 0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    if (text.size()>22){


        if( !textTexture.loadFromRenderedText( text.substr(0,22) , textColor,gRenderer,gFont ) )
        {
            std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
        }
        else {
            textTexture.render(position->getX()+10,position->getY()+5, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
        }

        if( !textTexture.loadFromRenderedText( text.substr(22) , textColor,gRenderer,gFont ) )
        {
            std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
        }
        else {
            textTexture.render(position->getX()+10,position->getY()+19, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
        }
    } else {
        if( !textTexture.loadFromRenderedText( text, textColor,gRenderer,gFont ) )
        {
            std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
        }
        else {
            textTexture.render(position->getX()+10,position->getY()+5, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
        }
    }

    gFont = TTF_OpenFont( "/home/amanda/CLionProjects/Project_1/fonts/RifficFree-Bold.ttf",12);

    if( !textTexture.loadFromRenderedText( title, textColor,gRenderer,gFont ) )
    {
        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
    }
    else {
        textTexture.render(position->getX(),position->getY()-10, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
    }




}