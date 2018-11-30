//
// Created by amanda on 18/11/18.
//

#include "PlayerStatTexture.h"
#include "ElementTexture.h"

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
    gFont = TTF_OpenFont( "fonts/04B_03__.TTF",14);
    TextTexture textTexture;

    if( gFont == nullptr ) {
        std::cout <<"Failed to load lazy font! SDL_ttf Error: "<< TTF_GetError() <<std::endl;
    }

    SDL_Color textColor= {255,179,91};

    auto *elementTexture =new ElementTexture();

    elementTexture->loadImageFromFile("assets/tiles/player_stat.png",gRenderer);

    auto  *sdl_rect= new SDL_Rect({0,0,32,32});
    elementTexture->render(position.getX(),position.getY(), nullptr,gRenderer);


    elementTexture->loadImageFromFile(player->getType(),gRenderer);

    elementTexture->render(position.getX()+154,position.getY()+15, sdl_rect,gRenderer);

    /** START: THIS IS FOR THE BORDER OF PLAYER INFORMATION **/


    SDL_Rect fillRect= {position.getX()+11,
                        position.getY()+19,
                        (int) (124*
                        (player->getClasse()->getStamina()*1.0/
                        player->getClasse()->getMaxStamina())),
                        10};

    SDL_SetRenderDrawColor( gRenderer, 237,67,55,0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );

    if (!textTexture.loadFromRenderedText(
            player->getClasse()->getName()+" : "+player->getName(),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+10,position.getY()+5, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    textColor= {255,255,255};

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->attackPower(0)),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+51,position.getY()+36, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->defensePower()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+117,position.getY()+36, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    textColor= {50,50,50};

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->getStrength()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+39,position.getY()+68, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->getDefense()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+81,position.getY()+68, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }
    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->getDexterity()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+123,position.getY()+68, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->getWillpower()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+39,position.getY()+98, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->getWisdom()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+81,position.getY()+98, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }

    if (!textTexture.loadFromRenderedText(
            std::to_string(player->getClasse()->getLuck()),textColor,gRenderer,gFont) ){
        std::cout << "ERROR" <<std::endl;
    }else {
        textTexture.render(position.getX()+123,position.getY()+98, nullptr,0.0, nullptr, SDL_FLIP_NONE,gRenderer);
    }
    auto *s=new SDL_Rect({0,0,32,32});

    int j=0;
    for (int i = 0; i <player->getInventory()->size() ; ++i) {
        elementTexture->loadImageFromFile(player->getInventory()->at(i)->getType(),gRenderer);

        if (i>1){j=1;}
        elementTexture->render(
                position.getX()+140+(i%2)*24,
                position.getY()+70+j*25,
                s,
                gRenderer);

        std::cout << " I : " << i << std::endl;


    }

    TTF_CloseFont(gFont);
    delete elementTexture;
    delete sdl_rect;

}



void PlayerStatTexture::setPlayer(Player *player) {
    PlayerStatTexture::player = player;
}


void PlayerStatTexture::setPosition(const Position &position) {
    PlayerStatTexture::position = position;
}
