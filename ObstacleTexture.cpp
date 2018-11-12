//
// Created by amanda on 08/11/18.
//

#include "ObstacleTexture.h"


ObstacleTexture::ObstacleTexture() {
    //Initialize
    obstacleTexture= NULL;
    oWidth = 32;
    oHeight = 32;
    obstacle.setPosition(Position(0,0));
}




ObstacleTexture::~ObstacleTexture() {
    free();
}



void ObstacleTexture::free(){
    //Free texture if it exists
    if(  obstacleTexture!= NULL )
    {
        SDL_DestroyTexture( obstacleTexture);
        obstacleTexture = NULL;
        oWidth = 0;
        oHeight = 0;
    }
}


bool ObstacleTexture::loadImageFromFile(std::string path, SDL_Renderer* gRenderer) {
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
            oWidth = loadedSurface->w;
            oHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    obstacleTexture= newTexture;
    return obstacleTexture != NULL;
}

SDL_Texture *ObstacleTexture::getObstacleTexture() const {
    return obstacleTexture;
}

void ObstacleTexture::setObstacleTexture(SDL_Texture *obstacleTexture) {
    ObstacleTexture::obstacleTexture = obstacleTexture;
}

int ObstacleTexture::getOWidth() const {
    return oWidth;
}

void ObstacleTexture::render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer ) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, oWidth, oHeight };
    //Set clip rendering dimensions
    if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy( gRenderer, obstacleTexture, clip, &renderQuad );
}

void ObstacleTexture::setOWidth(int oWidth) {
    ObstacleTexture::oWidth = oWidth;
}

int ObstacleTexture::getOHeight() const {
    return oHeight;
}

void ObstacleTexture::setOHeight(int oHeight) {
    ObstacleTexture::oHeight = oHeight;
}

Obstacle &ObstacleTexture::getObstacle()  {
    return obstacle;
}

void ObstacleTexture::setObstacle(const Obstacle &obstacle) {
    ObstacleTexture::obstacle = obstacle;
}


