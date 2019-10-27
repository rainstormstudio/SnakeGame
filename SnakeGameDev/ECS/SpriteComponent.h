#pragma once
#include "../Graphics.h"
#include "Components.h"

class SpriteComponent : public Component{
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;

    SpriteComponent(std::string path){
        setTexture(path);
    }

    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }

    void setTexture(std::string path){
        texture = Graphics::loadTexture(path);
    }

    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void update(double deltaTime) override{
        destRect.x = static_cast<int>(round(transform->position.x));
        destRect.y = static_cast<int>(round(transform->position.y));
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override{
        SDL_Point center;
        center.x = srcRect.w / 2;
        center.y = srcRect.h / 2;
        Graphics::drawTexture(texture, srcRect, destRect, transform->angle, center, SDL_FLIP_NONE);
    }
};
