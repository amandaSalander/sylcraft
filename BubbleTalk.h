//
// Created by amanda on 21/11/18.
//

#ifndef PROJECT_1_BUBBLETALK_H
#define PROJECT_1_BUBBLETALK_H

#include <SDL2/SDL.h>
#include "TextTexture.h"
#include <SDL2/SDL_ttf.h>

#include <string>
#include "Position.h"

class BubbleTalk {
private:
    Position *position;
public:
    BubbleTalk(Position *position);
    void render(std::string title,std::string text,SDL_Renderer *gRenderer);
};


#endif //PROJECT_1_BUBBLETALK_H
