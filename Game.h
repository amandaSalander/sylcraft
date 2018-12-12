//
// Created by amanda on 12/12/18.
//

#ifndef PROJECT_1_GAME_H
#define PROJECT_1_GAME_H


#include <SDL2/SDL_system.h>
#include <string>
#include "Timer.h"
#include "CarteTexture.h"

class Game {
private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 1160;
    const int SCREEN_HEIGHT = 640;
    //The window we'll be rendering to
    SDL_Window* gWindow= nullptr;
    //The window renderer
    SDL_Renderer* gRenderer = nullptr;
    //Current displayed texture
    SDL_Texture* gTexture = nullptr;
    Timer timestep;
    CarteTexture *carteTexture;
    float times=0;
    float start=0;



public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );

    int main( int argc, char* args[] );

};


#endif //PROJECT_1_GAME_H
