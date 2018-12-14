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
#include "Boss.h"
#include "Menu.h"

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
SDL_Texture* gTexture = nullptr;

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );
Timer timestep;


CarteTexture carteTexture;


float times=0;
float start=0;


bool init() {
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
        gWindow = SDL_CreateWindow( "SylCraft @amandaSalander", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
    /** stateInGame
     * if 1 first menu
     * if 2 choice of number of player
     * if 3 choice of carte
     * if 4 playing game **/

    int stateInGame=1;
    std::string filename="cartes/carte_3.txt";

    Carte carte1(filename);

    Player c("Eazeman","Killer Bee",new Classes("warrior"),Position(400,400));
    Player d("Nil","Killer Bee",new Classes("mage"),Position(500,400));
    Player k("Lorr","Killer Bee",new Classes("knight"),Position(600,500));
    Player i("Jaina","Killer Bee",new Classes("wizard"),Position(200,500));

    c.setType("assets/players/warrior_1.png");
    c.setPosition(Position(300,200));

    d.setType("assets/players/mage_1.png");
    d.setPosition(Position(600,400));


    k.setType("assets/players/knight_2.png");
    k.setPosition(Position(600,500));

    i.setType("assets/players/wizard_1.png");
    i.setPosition(Position(200,500));

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
//                SDL_RenderClear( gRenderer );
                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, nullptr, nullptr);
                //Update screen
                carteTexture.setCarte(&carte1);

                if (stateInGame==4){
                    PlayerStatTexture playerStatTexture;
                    playerStatTexture.setPlayer(new Player(c));
                    playerStatTexture.setPosition(Position(960,0));
                    playerStatTexture.render(gRenderer);



                    playerStatTexture.setPlayer(new Player(d));
                    playerStatTexture.setPosition(Position(960,140));
                    playerStatTexture.render(gRenderer);

                    playerStatTexture.setPlayer(new Player(k));
                    playerStatTexture.setPosition(Position(960,280));
                    playerStatTexture.render(gRenderer);

                    playerStatTexture.setPlayer(new Player(i));
                    playerStatTexture.setPosition(Position(960,280+140));
                    playerStatTexture.render(gRenderer);


                }

                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 ) {

                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if( e.type == SDL_KEYDOWN ) {
                        if (stateInGame==4){
                            carteTexture.changeCurrentRender(e.key.keysym.sym,times,start);

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

                        if (e.key.keysym.sym==SDLK_RETURN){
                            stateInGame= 4;
                        }




                    }
                }
                times =times + timestep.getTicks() / 1000.f;

                if (stateInGame==4){
                    carteTexture.getCarte()->addPlayerToMap(new Player(c),593);
                    carteTexture.getCarte()->addPlayerToMap(new Player(d),596);
                    carteTexture.getCarte()->addPlayerToMap(new Player(k),597);
                    carteTexture.getCarte()->addPlayerToMap(new Player(i),598);
                    carteTexture.render(gRenderer);
                }else if(stateInGame==1) {
                    ElementTexture elementTexture;

                    elementTexture.loadImageFromFile("assets/tiles/wallpaper.jpg",gRenderer);
                    elementTexture.render(0,0, nullptr,gRenderer);
                    Menu menu("menu_1");
                    TTF_Font *gFont = nullptr;
                    TTF_Init();
                    gFont = TTF_OpenFont( "fonts/RifficFree-Bold.ttf",64);
                    SDL_Color textColor= {255,255,255};
                    TextTexture textTexture;
                    if( !textTexture.loadFromRenderedText( menu.getTitle(), textColor,gRenderer,gFont ) )
                    {
                        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
                    }
                    else {
                        textTexture.render(450,100, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
                    }
                    gFont = TTF_OpenFont( "fonts/RifficFree-Bold.ttf",32);
                    if( !textTexture.loadFromRenderedText( menu.getSubtitle(), textColor,gRenderer,gFont ) )
                    {
                        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
                    }
                    else {
                        textTexture.render(450,180, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
                    }

                    textColor={255,255,255};


                    elementTexture.loadImageFromFile("assets/tiles/start.png",gRenderer);
                    elementTexture.render(430,220, nullptr,gRenderer);

                    if( !textTexture.loadFromRenderedText( menu.getChoices()->at(0), textColor,gRenderer,gFont ) )
                    {
                        std::cout <<"Failed to load TEXT ! SDL_ttf Error: "<<std::endl;
                    }
                    else {
                        textTexture.render(530,290, nullptr,0.0, nullptr,SDL_FLIP_NONE,gRenderer);
                    }

                    TTF_CloseFont(gFont);
                }



                SDL_RenderPresent( gRenderer );

                timestep.start();

            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}