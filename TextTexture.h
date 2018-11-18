//
// Created by amanda on 18/11/18.
//

#ifndef PROJECT_1_TEXTTEXTURE_H
#define PROJECT_1_TEXTTEXTURE_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <iostream>

class TextTexture {
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    //Image dimensions
    int mWidth;
    int mHeight;
public:
    //Initializes variables
    TextTexture();

    //Deallocates memory
    ~TextTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path,SDL_Renderer *gRenderer );

    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor , SDL_Renderer *gRenderer,TTF_Font *gFont);

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render(
            int x,
            int y,
            SDL_Rect* clip = nullptr,
            double angle = 0.0,
            SDL_Point* center = nullptr,
            SDL_RendererFlip flip = SDL_FLIP_NONE,
            SDL_Renderer *gRenderer= nullptr);

    //Gets image dimensions
    int getWidth();
    int getHeight();
};


#endif //PROJECT_1_TEXTTEXTURE_H
