#pragma once
#include <string>
#include "SDL2/SDL.h"
#include "Components.h"

class ColliderComponent : public Component{
public:
    SDL_Rect collider;
    std::string tag;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    TransformComponent* transform;

    ColliderComponent(std::string initTag){
        printf("initializing ...\n");
        printf("colliderComponent address = %p\n", this);
        tag = initTag;
        collider.x = 0;
        collider.y = 0;
        collider.h = collider.w = 32;
    }

    ColliderComponent(std::string initTag, int posX, int posY, int size){
        printf("initializing ... 2nd ...\n");
        tag = initTag;
        collider.x = posX;
        collider.y = posY;
        collider.h = collider.w = size;
        printf("  collider collider.w = %i\n", collider.w);
        printf("  collider collider.h = %i\n", collider.h);
        printf("  collider collider.x = %i\n", collider.x);
        printf("  collider collider.y = %i\n", collider.y);
        printf("  collider address = %p\n", &collider);
        printf("this address = %p\n", this);
    }

    void init() override{
        if (!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>(collider.x, collider.y, 0, collider.w, collider.h, 1);
        }
        transform = &entity->getComponent<TransformComponent>();

        texture = Graphics::loadTexture("assets/collider.png");
        srcRect = {0, 0, 32, 32};
        destRect = {collider.x, collider.y, collider.w, collider.h};
        printf("init\n");
        printf("  collider collider.w = %i\n", collider.w);
        printf("  collider collider.h = %i\n", collider.h);
        printf("  collider collider.x = %i\n", collider.x);
        printf("  collider collider.y = %i\n", collider.y);
        printf("  collider address = %p\n", &collider);
        printf("  collider destRect.w = %i\n", destRect.w);
        printf("  collider destRect.h = %i\n", destRect.h);
        printf("  collider destRect.x = %i\n", destRect.x);
        printf("  collider destRect.y = %i\n", destRect.y);
        printf("this address = %p\n", this);
    }

    void update(double deltaTime) override{
        if (tag != "map"){
            collider.x = static_cast<int>(round(transform->position.x));
            collider.y = static_cast<int>(round(transform->position.y));
            collider.w = transform->width * transform->scale;
            collider.h = transform->height * transform->scale;
        }
        destRect.x = collider.x - Game::camera.x;
        destRect.y = collider.y - Game::camera.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;/*
        printf("update ...\n");
        printf("collider destRect.w = %i\n", destRect.w);
        printf("collider destRect.h = %i\n", destRect.h);
        printf("collider destRect.x = %i\n", destRect.x);
        printf("collider destRect.y = %i\n", destRect.y);*/
    }

    void draw() override{
        SDL_Point center = {collider.w / 2, collider.h / 2};
        Graphics::drawTexture(texture, srcRect, destRect, 0, center, SDL_FLIP_NONE);
        /*printf("draw ...\n");
        printf("collider destRect.w = %i\n", destRect.w);
        printf("collider destRect.h = %i\n", destRect.h);
        printf("collider destRect.x = %i\n", destRect.x);
        printf("collider destRect.y = %i\n", destRect.y);
        printf("collider drew\n");*/
    }
};
