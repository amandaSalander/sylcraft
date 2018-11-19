//
// Created by amanda on 11/11/18.
//

#ifndef PROJECT_1_ELEMENTTEXTURE_H
#define PROJECT_1_ELEMENTTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Element.h"

class ElementTexture {
private:
    SDL_Texture* elementTexture;
    int eWidth;
    int eHeight;

public:
    ElementTexture();
    virtual ~ElementTexture();
    virtual void free();

    virtual bool loadImageFromFile(const std::string &path, SDL_Renderer* gRenderer);

    virtual void render(int x, int y, SDL_Rect *clip, SDL_Renderer *gRenderer);


    SDL_Texture *getElementTexture() const;

    void setElementTexture(SDL_Texture *elementTexture);

    int getEWidth() const;

    void setEWidth(int eWidth);

    int getEHeight() const;

    void setEHeight(int eHeight);



};


#endif //PROJECT_1_ELEMENTTEXTURE_H
