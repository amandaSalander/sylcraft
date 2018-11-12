//
// Created by amanda on 11/11/18.
//

#ifndef PROJECT_1_LOOTTEXTURE_H
#define PROJECT_1_LOOTTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "Loot.h"
#include "ElementTexture.h"

class LootTexture : public ElementTexture{

private:
    SDL_Texture* lootTexture;
    //Image dimensions
    int tWidth;
    int tHeight;
    Loot loot;
public:
    LootTexture();

    virtual  ~LootTexture();
    void free();

    bool loadImageFromFile(std::string path, SDL_Renderer* gRenderer);

    void render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer );

    SDL_Texture *getLootTexture();

    void setLootTexture(SDL_Texture *lootTexture);

    int getTWidth() const;

    void setTWidth(int tWidth);

    int getTHeight() const;

    void setTHeight(int tHeight);

    Loot &getLoot();

    void setLoot(const Loot &loot);
};


#endif //PROJECT_1_LOOTTEXTURE_H
