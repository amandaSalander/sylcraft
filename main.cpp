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
#include "PlayerStatTexture.h"
#include "HarmingObjects.h"
#include "Timer.h"
#include "BubbleTalk.h"
#include "PlayerLabel.h"
#include "Quest.h"


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
SDL_Window* gWindow = nullptr;



//The window renderer
SDL_Renderer* gRenderer = nullptr;
//Current displayed texture
//
SDL_Texture* gTexture = nullptr;

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );
Timer timestep;
PlayerTexture playerTexture;
SDL_Rect playerRectangle;
ObstacleTexture obstacleTexture;
LootTexture lootTexture;
CarteTexture carteTexture;

Player c("Kate","Killer Bee",new Classes("warrior"),Position(400,400));
Player d("Nil","Killer Bee",new Classes("mage"),Position(500,400));
Player e("Lorr","Killer Bee",new Classes("knight"),Position(600,500));


std::string filename="cartes/carte_1.txt";

Carte carte1(filename);

float times=0;
float start=0;


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
        if( gWindow == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            //gScreenSurface = SDL_GetWindowSurface( gWindow );
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == nullptr ) {
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
    if( gTexture == nullptr ) {
        printf( "Failed to load texture image!\n" );
        success = false;
    }


    return success;
}



void close() {
    playerTexture.free();
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = nullptr;
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
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
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == nullptr )
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
    {
        Quest quest("find_book");
    }

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
//            printf( "Failed to initialize!\n" );
            //While application is running
            while( !quit )
            {
                SDL_UpdateWindowSurface( gWindow );
                //Clear screen
                SDL_RenderClear( gRenderer );
                //Render texture to screen
//                printf( "Failed to initialize!\n" );
                SDL_RenderCopy( gRenderer, gTexture, nullptr, nullptr);
                //Update screen
                carteTexture.setCarte(&carte1);


//                c.addToIventory(new Item("book"));

                c.setType("assets/players/warrior_1.png");
                c.setPosition(Position(300,200));

                d.setType("assets/players/mage_1.png");
                d.setPosition(Position(600,400));

                PlayerStatTexture playerStatTexture;
                playerStatTexture.setPlayer(new Player(c));
                playerStatTexture.setPosition(Position(960,0));
                playerStatTexture.render(gRenderer);



                playerStatTexture.setPlayer(new Player(d));
                playerStatTexture.setPosition(Position(960,140));
                playerStatTexture.render(gRenderer);

                carteTexture.getCarte()->addPlayerToMap(new Player(c),593);
                carteTexture.getCarte()->addPlayerToMap(new Player(d),596);






                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 ) {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if( e.type == SDL_KEYDOWN ) {

                        carteTexture.changeCurrentRender(e.key.keysym.sym,times,start,gRenderer);

                        carteTexture.PickUpLoot(e.key.keysym.sym);

                        carteTexture.updateCurrentPlayer(e.key.keysym.sym);

                        if (e.key.keysym.sym==SDLK_b){
                            Loot l("heart");

                            l.setPosition(Position(64,94));

                            std::cout << carteTexture.getCarte()->addLootToMap(new Loot(l)) <<std::endl;

                        }
                        if (e.key.keysym.sym==SDLK_b){

                        }


                    }
                }
                times =times + timestep.getTicks() / 1000.f;


                carteTexture.render(gRenderer);



                SDL_Delay(50);
                SDL_RenderPresent( gRenderer );

                timestep.start();

            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}