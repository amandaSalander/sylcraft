//
// Created by amanda on 11/11/18.
//

#include "ElementTexture.h"


ElementTexture::ElementTexture() {
    eWidth=0;
    eHeight=0;
    elementTexture= nullptr;
}

ElementTexture::~ElementTexture() {
    free();
}
void ElementTexture::free() {
    if (elementTexture!=nullptr){
        SDL_DestroyTexture(elementTexture);
        elementTexture=nullptr;
        eHeight=0;
        eWidth=0;

    }
}

bool ElementTexture::loadImageFromFile(const std::string &path, SDL_Renderer *gRenderer) {

    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            eWidth = loadedSurface->w;
            eHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    elementTexture= newTexture;
    return elementTexture!= nullptr;

}


void ElementTexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer *gRenderer) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, eWidth, eHeight};
    //Set clip rendering dimensions
    if( clip != nullptr ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, elementTexture, clip, &renderQuad );
}


SDL_Texture *ElementTexture::getElementTexture() const {
    return elementTexture;
}

void ElementTexture::setElementTexture(SDL_Texture *elementTexture) {
    ElementTexture::elementTexture = elementTexture;
}

int ElementTexture::getEWidth() const {
    return eWidth;
}

void ElementTexture::setEWidth(int eWidth) {
    ElementTexture::eWidth = eWidth;
}

int ElementTexture::getEHeight() const {
    return eHeight;
}

void ElementTexture::setEHeight(int eHeight) {
    ElementTexture::eHeight = eHeight;
}
