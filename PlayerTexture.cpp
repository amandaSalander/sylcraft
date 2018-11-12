//
// Created by amanda on 04/11/18.
//

#include "PlayerTexture.h"

// Initialisation
PlayerTexture::PlayerTexture() {
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
    Player player(Player("Sylia","lokrkan", Classes(10,10,10,10,10,10,10,"nul"),Position(0,0) ));
}


// Destructure
PlayerTexture::~PlayerTexture() {
    free();
}






void PlayerTexture::free(){
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

SDL_Texture *PlayerTexture::getMTexture() const {
    return mTexture;
}

void PlayerTexture::setMTexture(SDL_Texture *mTexture) {
    PlayerTexture::mTexture = mTexture;
}

int PlayerTexture::getMWidth() const {
    return mWidth;
}

void PlayerTexture::setMWidth(int mWidth) {
    PlayerTexture::mWidth = mWidth;
}

int PlayerTexture::getMHeight() const {
    return mHeight;
}

void PlayerTexture::setMHeight(int mHeight) {
    PlayerTexture::mHeight = mHeight;
}

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

void PlayerTexture::render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer ) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    //Set clip rendering dimensions
    if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

const Player &PlayerTexture::getPlayer() const {
    return player;
}

void PlayerTexture::setPlayer(const Player &player) {
    PlayerTexture::player = player;
}

bool PlayerTexture::loadImageFromFile(std::string path, SDL_Renderer* gRenderer) {
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}