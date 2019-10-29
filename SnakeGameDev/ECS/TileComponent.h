#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"
#include <string>

#define DIRT                        0
#define GRASS                       1
#define BORDER_UP                   2
#define BORDER_DOWN                 3
#define BORDER_LEFT                 4
#define BORDER_RIGHT                5
#define BORDER_CORNER_TOPLEFT       6
#define BORDER_CORNER_TOPRIGHT      7
#define BORDER_CORNER_BOTTOMLEFT    8
#define BORDER_CORNER_BOTTOMRIGHT   9

class TileComponent : public Component{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    int angle;

    TileComponent() = default;

    ~TileComponent(){
        SDL_DestroyTexture(texture);
    }

    TileComponent(int srcX, int srcY, int posX, int posY, int theta, std::string path){
        texture = Graphics::loadTexture(path);
        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = 32;

        destRect.x = posX;
        destRect.y = posY;
        destRect.w = destRect.h = 64;

        angle = theta;
    }

    void draw() override{
        SDL_Point center;
        center.x = center.y = 32 * 2 / 2;
        Graphics::drawTexture(texture, srcRect, destRect, angle, center, SDL_FLIP_NONE);
    }

};
