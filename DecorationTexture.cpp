//
// Created by amanda on 11/11/18.
//

#include "DecorationTexture.h"


DecorationTexture::DecorationTexture() {
    decorationTexture= NULL;
    dWidth = 32;
    dHeight = 32;
    decoration.setPosition(Position(0,0));
}

DecorationTexture::~DecorationTexture() {
    free();
}

void DecorationTexture::free() {
    if (decorationTexture!=NULL){
        SDL_DestroyTexture(decorationTexture);
        decorationTexture=NULL;
        dHeight=0;
        dWidth=0;
    }
}

bool DecorationTexture::loadImageFromFile(std::string path, SDL_Renderer *gRenderer) {
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
            dWidth = loadedSurface->w;
            dHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    decorationTexture= newTexture;
    return decorationTexture!= NULL;
}

void DecorationTexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer *gRenderer) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, dWidth, dWidth};
    //Set clip rendering dimensions
    if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, decorationTexture, clip, &renderQuad );
}

SDL_Texture *DecorationTexture::getDecorationTexture() const {
    return decorationTexture;
}

void DecorationTexture::setDecorationTexture(SDL_Texture *decorationTexture) {
    DecorationTexture::decorationTexture = decorationTexture;
}

int DecorationTexture::getDWidth() const {
    return dWidth;
}

void DecorationTexture::setDWidth(int dWidth) {
    DecorationTexture::dWidth = dWidth;
}

int DecorationTexture::getDHeight() const {
    return dHeight;
}

void DecorationTexture::setDHeight(int dHeight) {
    DecorationTexture::dHeight = dHeight;
}

Decoration &DecorationTexture::getDecoration(){
    return decoration;
}

void DecorationTexture::setDecoration(const Decoration &decoration) {
    DecorationTexture::decoration = decoration;
}
