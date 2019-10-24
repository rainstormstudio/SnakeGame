#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component{
private:
    double speed;
public:
    Vector2D position;
    Vector2D velocity;

    TransformComponent(){
        TransformComponent(0, 0, 32);
    }
    TransformComponent(int x, int y, int initSpeed){
        position.x = x; position.y = y; speed = initSpeed;
    }

    void init() override{
        velocity.x = 0; 
        velocity.y = 0;
    }

    void update(double deltaTime) override{
        position.x += velocity.x * speed * deltaTime;
        position.y += velocity.y * speed * deltaTime;
    }
};
