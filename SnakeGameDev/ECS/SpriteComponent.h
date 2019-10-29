#pragma once
#include "../Graphics.h"
#include "../Game.h"
#include "Components.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component{
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frames = 0;
    int aniSpeed = 100;

public:
    int animIndex = 0;
    std::map<const char*, Animation> animations;
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent() = default;

    SpriteComponent(std::string path){
        setTexture(path);
    }

    SpriteComponent(std::string path, bool isAnimated){
        animated = isAnimated;

        Animation moveFront = Animation(0, 4, 150);
        Animation moveBack = Animation(1, 4, 150);
        Animation moveSide = Animation(2, 4, 150);

        animations.emplace("MoveFront", moveFront);
        animations.emplace("MoveBack", moveBack);
        animations.emplace("MoveSide", moveSide);

        play("MoveFront");
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
        if (animated){
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / aniSpeed) % frames);
        }
        srcRect.y = animIndex * transform->height;

        destRect.x = static_cast<int>(round(transform->position.x)) - Game::camera.x;
        destRect.y = static_cast<int>(round(transform->position.y)) - Game::camera.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override{
        SDL_Point center;
        center.x = srcRect.w / 2;
        center.y = srcRect.h / 2;
        Graphics::drawTexture(texture, srcRect, destRect, transform->angle, center, spriteFlip);
    }

    void play(const char* animName){
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        aniSpeed = animations[animName].speed;
    }
};
