#pragma once
#include "ECS.h"
#include "Components.h"
#include "../Game.h"


enum Controls{
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    CONTROLS_TOTAL
};

class KeyboardController : public Component{
private:
    bool controls[CONTROLS_TOTAL];
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
        for (int i = 0; i < CONTROLS_TOTAL; i ++){
            controls[i] = false;
        }
    }

    void update(double deltaTime) override{
        while (SDL_PollEvent(&Game::event) != 0){
            if (Game::event.type == SDL_KEYDOWN){
                switch (Game::event.key.keysym.sym){
                    case SDLK_w: controls[MOVE_UP] = true; break;
                    case SDLK_s: controls[MOVE_DOWN] = true; break;
                    case SDLK_a: controls[MOVE_LEFT] = true; break;
                    case SDLK_d: controls[MOVE_RIGHT] = true; break;
                }
            }

            if (Game::event.type == SDL_KEYUP){
                switch (Game::event.key.keysym.sym){
                    case SDLK_w: controls[MOVE_UP] = false; break;
                    case SDLK_s: controls[MOVE_DOWN] = false; break;
                    case SDLK_a: controls[MOVE_LEFT] = false; break;
                    case SDLK_d: controls[MOVE_RIGHT] = false; break;
                }
            }

            transform->velocity.x = 0;
            transform->velocity.y = 0;
            if (controls[MOVE_UP]){
                transform->velocity.y = -1;
                sprite->play("MoveBack");
            }
            if (controls[MOVE_DOWN]){
                transform->velocity.y = 1;
                sprite->play("MoveFront");
            }
            if (controls[MOVE_LEFT]){
                transform->velocity.x = -1;
                sprite->play("MoveSide");
                sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
            }
            if (controls[MOVE_RIGHT]){
                transform->velocity.x = 1;
                sprite->play("MoveSide");
                sprite->spriteFlip = SDL_FLIP_NONE;
            }
        }
    }
};
