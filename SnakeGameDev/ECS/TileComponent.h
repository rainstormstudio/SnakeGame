#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"
#include <string>

class TileComponent : public Component{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    Vector2D position;
    int angle;

    TileComponent() = default;

    ~TileComponent(){
        SDL_DestroyTexture(texture);
    }

    TileComponent(int srcX, int srcY, int posX, int posY, int theta, int tileSize, int tileScale, std::string id){
        position.x = posX;
        position.y = posY;
        texture = Game::assets->getTexture(id);
        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = tileSize;

        destRect.x = posX;
        destRect.y = posY;
        destRect.w = destRect.h = tileSize * tileScale;

        angle = theta;
    }

    void update(double deltaTime) override{
        destRect.x = position.x - Game::camera.x;
        destRect.y = position.y - Game::camera.y; 
    }

    void draw() override{
        SDL_Point center;
        center.x = center.y = 32 * 2 / 2;
        Graphics::drawTexture(texture, srcRect, destRect, angle, center, SDL_FLIP_NONE);
    }

};
