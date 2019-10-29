#pragma once
#include "ECS.h"
#include "Components.h"
#include "../Game.h"

class KeyboardController : public Component{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update(double deltaTime) override{
        while (SDL_PollEvent(&Game::event) != 0){
            if (Game::event.type == SDL_KEYDOWN){
                switch (Game::event.key.keysym.sym)
                {
                case SDLK_w:
                    transform->velocity.y = -1;
                    sprite->play("MoveBack");
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->play("MoveFront");
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->play("MoveSide");
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    sprite->play("MoveSide");
                    break;
                default:
                    break;
                }
            }

            if (Game::event.type == SDL_KEYUP){
                switch (Game::event.key.keysym.sym)
                {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
                }
            }
        }
    }
};
