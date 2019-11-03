#pragma once
#include "ECS.h"
#include "Components.h"

class ProjectileComponent : public Component{
private:
    TransformComponent* transform;
    int range = 0;
    double speed = 0;
    int distance = 0;
    Vector2D velocity;
public:
    ProjectileComponent(int initRange, double initSpeed, Vector2D vel){
        range = initRange;
        speed = initSpeed;
        velocity = vel;
    }

    ~ProjectileComponent(){};

    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        transform->velocity = velocity;
    }

    void update(double deltaTime) override{
        printf("projectile update ready\n");
        distance += static_cast<int>(round(speed * deltaTime));
        if (distance > range){
            printf("out of range\n");
            entity->destroy();
        }
        else if (transform->position.x > Game::camera.x + Game::camera.w ||
        transform->position.y > Game::camera.y + Game::camera.h ||
        transform->position.x < Game::camera.x ||
        transform->position.y < Game::camera.y){
            printf("out of bounds\n");
            entity->destroy();
        }
        printf("projectile updated\n");
    }
};
