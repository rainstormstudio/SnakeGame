#pragma once
#include "ECS.h"
#include "Components.h"
#include "../Game.h"

class KeyboardController : public Component{
public:
    TransformComponent* transform;

    void init() override{
        transform = &entity->getComponent<TransformComponent>();
    }

    void update(double deltaTime) override{
        while (SDL_PollEvent(&Game::event) != 0){
            if (Game::event.type == SDL_KEYDOWN){
                switch (Game::event.key.keysym.sym)
                {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
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
