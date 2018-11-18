/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "PlayerTexture.h"
#include "Carte.h"
#include "ObstacleTexture.h"
#include "LootTexture.h"
#include "CarteTexture.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1160;
const int SCREEN_HEIGHT = 640;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
//Current displayed texture
//
SDL_Texture* gTexture = NULL;

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

PlayerTexture playerTexture;
SDL_Rect playerRectangle;
ObstacleTexture obstacleTexture;
LootTexture lootTexture;
CarteTexture carteTexture;

Player a;
Player b;



bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            //gScreenSurface = SDL_GetWindowSurface( gWindow );
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL ) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else{

                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}



bool loadMedia() {
    //Loading success flag
    bool success = true;
    //Load PNG texture
    gTexture = loadTexture( "texture.png" );
    if( gTexture == NULL ) {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    if (!playerTexture.loadImageFromFile("katia_civil.png",gRenderer)){
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    else{
        playerRectangle.x=0;
        playerRectangle.y=0;
        playerRectangle.w=32;
        playerRectangle.h=32;
    }
    if (!obstacleTexture.loadImageFromFile("crystal.gif",gRenderer)){
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if (!lootTexture.loadImageFromFile("bag.gif",gRenderer)){
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    playerTexture.getPlayer().setPosition(Position(300,240));
    playerTexture.getPlayer().setType("haru_civil.png");



    a.setType("katia_civil.png");
    a.setPosition(Position(200,200));



    b.setType("Aldusa_Grai_de_Civille.png");
    b.setPosition(Position(300,400));




    return success;
}



void close() {
    playerTexture.free();
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
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
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}



int main( int argc, char* args[] )
{
    int player(0);
    Carte carte("cdff");

    Carte carte1("ccc",0);

    std::cout<<carte.getHauteur()<<std::endl;

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit )
            {
                SDL_UpdateWindowSurface( gWindow );
                //Clear screen
                SDL_RenderClear( gRenderer );
                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                //Update screen
                carteTexture.setCarte(carte1
                );

                carteTexture.getCarte().addPlayerToMap(new Player(b),595);
                carteTexture.getCarte().addPlayerToMap(new Player(a),594);
                carteTexture.getCarte().addPlayerToMap(new Player(playerTexture.getPlayer()),593);


                //Handle events on queue
                int k_w(0),k_h(0);
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if( e.type == SDL_KEYDOWN ) {

                        carteTexture.changeCurrentRender(&(carteTexture.getSdl_rect()),e.key.keysym.sym);
//                        if (e.key.keysym.sym==SDLK_1){
                        carteTexture.updateCurrentPlayer(e.key.keysym.sym);

//                        }



                    }
                }










                carteTexture.render(gRenderer);




                SDL_RenderPresent( gRenderer );

            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}