#pragma once
#include "../Graphics.h"
#include "Components.h"

class SpriteComponent : public Component{
private:
    TransformComponent* position;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
public:
    SpriteComponent() = default;
    SpriteComponent(std::string path, SDL_Renderer* renderer){
        texture = Graphics::loadTexture(path, renderer);
    }
    void init() override{
        position = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 32;
    }
    void update(double deltaTime) override{
        destRect.x = (int)round(position->x());
        destRect.y = (int)round(position->y());
    }
    void draw(SDL_Renderer* renderer) override{
        SDL_Point center;
        center.x = center.y = 0;
        Graphics::drawTexture(texture, srcRect, destRect, 0, center, SDL_FLIP_NONE, renderer);
    }
};
