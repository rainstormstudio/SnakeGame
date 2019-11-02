#pragma once
#include "ECS.h"
#include "Components.h"

class ProjectileComponent : public Component{
private:
    TransformComponent* transform;
    int range = 0;
    int speed = 0;
    int distance = 0;
public:
    ProjectileComponent(int initRange, int initSpeed){
        range = initRange;
        speed = initSpeed;
    }

    ~ProjectileComponent(){};

    void init() override{
        transform = &entity->getComponent<TransformComponent>();
    }

    void update(double deltaTime) override{
        distance += static_cast<int>(round(speed * deltaTime));
        if (distance > range){
            printf("out of range\n");
            entity->destroy();
        }
        else if (transform->position.x > Game::camera.x + Game::camera.w || 
        transform->position.y > Game::camera.y + Game::camera.h ||
        transform->position.x < Game::camera.x ||
        transform->position.y < Game::camera.y){
            entity->destroy();
            printf("out of bounds\n");
        }
    }
};