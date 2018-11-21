//
// Created by amanda on 18/11/18.
//

#include <vector>
#include "PlayerStatTexture.h"
#include "TextTexture.h"


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
    TTF_Init();
    gFont = TTF_OpenFont( "/home/amanda/CLionProjects/Project_1/fonts/neuropol x rg.ttf",11);
    TextTexture textTexture;

    if( gFont == nullptr ) {
        std::cout <<"Failed to load lazy font! SDL_ttf Error: "<< TTF_GetError() <<std::endl;
    }

    SDL_Color textColor= {50,50,50};

    /** START: THIS IS FOR THE BORDER OF PLAYER INFORMATION **/
    SDL_Rect fillRect= {position.getX(),position.getY(),200,140};

    SDL_SetRenderDrawColor( gRenderer, 201,145,87,0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    fillRect.y+=2;
    fillRect.x+=2;
    fillRect.h-=4;
    fillRect.w-=4;


    SDL_SetRenderDrawColor( gRenderer, 225,173,109, 0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    /** END: THIS IS FOR THE BORDER OF PLAYER INFORMATION **/

    if( !textTexture.loadFromRenderedText( player->getClasse()->getName()+" : "+ player->getName(), textColor,gRenderer,gFont ) )
    {
        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
    }
    else {
        textTexture.render(position.getX()+5,position.getY()+5, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
    }

    /** This vector contain all of the skills of a player **/
    std::vector<std::string> liste;
    liste.emplace_back("Strength");
    liste.emplace_back("Stamina");
    liste.emplace_back("Defense");
    liste.emplace_back("Dexterity");
    liste.emplace_back("Wisdom");
    liste.emplace_back("Willpower");
    liste.emplace_back("Luck");

    /** For each item in vector we display the graphical bar that it belongs to**/
    for (int i = 0; i < liste.size(); ++i) {
        if( !textTexture.loadFromRenderedText(liste.at((size_t)i), textColor,gRenderer,gFont ) )
        {
            std::cout <<"Failed to load TEXT ! SDL_ttf Error at : " << liste.at((size_t)i) <<std::endl;
        }
        else {
            textTexture.render(position.getX()+5,position.getY()+20+i*15, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
            SDL_Rect interRect= {position.getX()+80,position.getY()+20+i*15,115,10};
            SDL_SetRenderDrawColor( gRenderer, 211,211,211, 0xFF );
            SDL_RenderFillRect( gRenderer, &interRect );

        }
    }

    /** For Each skills we display the exact percentage of the skill**/
    SDL_Rect interRect= {position.getX()+80,position.getY()+20, (int)( 115.0*(player->getClasse()->getStrength()/20.0 ) )  ,10};
    SDL_SetRenderDrawColor( gRenderer, 0,116,217, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );

    interRect= {position.getX()+80,position.getY()+35, (int)( 115.0*(player->getClasse()->getStamina()/20.0 ) )  ,10};
    SDL_SetRenderDrawColor( gRenderer, 255,65,54, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );

    interRect= {position.getX()+80,position.getY()+50, (int)( 115.0*(player->getClasse()->getDefense()/20.0 ) ) ,10};
    SDL_SetRenderDrawColor( gRenderer, 46,204,64, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );

    interRect= {position.getX()+80,position.getY()+65, (int)( 115.0*(player->getClasse()->getDexterity()/20.0 ) )  ,10};
    SDL_SetRenderDrawColor( gRenderer, 255,133,27, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );

    interRect= {position.getX()+80,position.getY()+80, (int)( 115.0*(player->getClasse()->getWisdom()/20.0 ) )  ,10};
    SDL_SetRenderDrawColor( gRenderer, 0,31,63, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );

    interRect= {position.getX()+80,position.getY()+95, (int)( 115.0*(player->getClasse()->getWillpower()/20.0 ) )  ,10};
    SDL_SetRenderDrawColor( gRenderer, 133,20,75, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );

    interRect= {position.getX()+80,position.getY()+110,(int)( 115.0*(player->getClasse()->getLuck()/20.0 ) ) ,10};
    SDL_SetRenderDrawColor( gRenderer, 61,153,112, 0xFF );
    SDL_RenderFillRect( gRenderer, &interRect );





}



void PlayerStatTexture::setPlayer(Player *player) {
    PlayerStatTexture::player = player;
}


void PlayerStatTexture::setPosition(const Position &position) {
    PlayerStatTexture::position = position;
}
