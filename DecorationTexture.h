//
// Created by amanda on 11/11/18.
//

#ifndef PROJECT_1_DECORATIONTEXTURE_H
#define PROJECT_1_DECORATIONTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "ElementTexture.h"
#include "Decoration.h"

class DecorationTexture : public ElementTexture {
private:
    SDL_Texture* decorationTexture;
    //Image dimensions
    int dWidth;
    int dHeight;
    Decoration decoration;

public:
    DecorationTexture();

    virtual  ~DecorationTexture();

    void free();

    bool loadImageFromFile(std::string path, SDL_Renderer* gRenderer);

    void render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer );

    SDL_Texture *getDecorationTexture() const;

    void setDecorationTexture(SDL_Texture *decorationTexture);

    int getDWidth() const;

    void setDWidth(int dWidth);

    int getDHeight() const;

    void setDHeight(int dHeight);

    Decoration &getDecoration();

    void setDecoration(const Decoration &decoration);
};


#endif //PROJECT_1_DECORATIONTEXTURE_H
