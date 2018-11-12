//
// Created by amanda on 08/11/18.
//

#ifndef PROJECT_1_OBSTACLETEXTURE_H
#define PROJECT_1_OBSTACLETEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Obstacle.h"
#include "ElementTexture.h"
#include <iostream>

class ObstacleTexture: virtual public ElementTexture {
private:
    //The actual hardware texture
    SDL_Texture* obstacleTexture;
    //Image dimensions
    int oWidth;
    int oHeight;
    Obstacle obstacle;

public:

    ObstacleTexture();
    virtual  ~ObstacleTexture();
    bool loadImageFromFile(std::string path, SDL_Renderer* gRenderer);
    void free();

    void render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer );

    SDL_Texture *getObstacleTexture() const;

    void setObstacleTexture(SDL_Texture *obstacleTexture);

    int getOWidth() const;

    void setOWidth(int oWidth);

    int getOHeight() const;

    void setOHeight(int oHeight);

    Obstacle &getObstacle();

    void setObstacle(const Obstacle &obstacle);

};


#endif //PROJECT_1_OBSTACLETEXTURE_H
