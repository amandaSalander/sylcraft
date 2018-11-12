//
// Created by amanda on 11/11/18.
//

#include "LootTexture.h"


LootTexture::LootTexture() {
    lootTexture= NULL;
    tWidth = 32;
    tHeight = 32;
    loot.setPosition(Position(0,0));
}

LootTexture::~LootTexture() {
    free();
}
void LootTexture::free() {
    //Free texture if it exists
    if(  lootTexture!= NULL )
    {
        SDL_DestroyTexture( lootTexture);
        lootTexture = NULL;
        tWidth = 0;
        tHeight = 0;
    }
}


bool LootTexture::loadImageFromFile(std::string path, SDL_Renderer *gRenderer) {
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
            tWidth = loadedSurface->w;
            tHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    lootTexture= newTexture;
    return lootTexture!= NULL;
}

void LootTexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer *gRenderer) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, tWidth, tHeight };
    //Set clip rendering dimensions
    if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, lootTexture, clip, &renderQuad );
}


SDL_Texture *LootTexture::getLootTexture(){
    return lootTexture;
}

void LootTexture::setLootTexture(SDL_Texture *lootTexture) {
    LootTexture::lootTexture = lootTexture;
}

int LootTexture::getTWidth() const {
    return tWidth;
}

void LootTexture::setTWidth(int tWidth) {
    LootTexture::tWidth = tWidth;
}

int LootTexture::getTHeight() const {
    return tHeight;
}

void LootTexture::setTHeight(int tHeight) {
    LootTexture::tHeight = tHeight;
}

Loot &LootTexture::getLoot() {
    return loot;
}

void LootTexture::setLoot(const Loot &loot) {
    LootTexture::loot = loot;
}
