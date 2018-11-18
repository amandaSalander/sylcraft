//
// Created by amanda on 04/11/18.
//

#include "PlayerTexture.h"

void PlayerTexture::changeCurrentRender(SDL_Rect *playerRectangle, SDL_Keycode key){

    if (playerRectangle->x >=64){
        playerRectangle->x=0;
    }
    else{
        playerRectangle->x= ( ( playerRectangle->x / 32 ) % 3 ) * 32 + 32 ;
    }
    playerRectangle->w=32;
    playerRectangle->h=32;

    switch (key){
        case SDLK_UP:
            playerRectangle->y=3*32;
            player.setPosition(
                    Position(
                            player.getPosition().getX()
                            ,player.getPosition().getY()-2
                            )
                    );
            break;
        case SDLK_DOWN:
            player.setPosition(
                    Position(
                            player.getPosition().getX()
                            ,player.getPosition().getY()+2
                    )
            );
            playerRectangle->y=0;
            break;
        case SDLK_LEFT:
            player.setPosition(
                    Position(
                            player.getPosition().getX()-2
                            ,player.getPosition().getY()
                    )
            );
            playerRectangle->y=32;
            break;
        case SDLK_RIGHT:
            player.setPosition(
                    Position(
                            player.getPosition().getX()+2
                            ,player.getPosition().getY()
                    )
            );
            playerRectangle->y=64;
            break;
        default:
            playerRectangle->y=0;
            break;

    }

}

Player &PlayerTexture::getPlayer() {
    return player;
}

void PlayerTexture::setPlayer(const Player &player) {
    PlayerTexture::player = player;
}
