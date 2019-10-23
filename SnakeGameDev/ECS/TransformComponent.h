#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component{
private:
    double speed;
public:
    Vector2D position;

    TransformComponent(){
        TransformComponent(0, 0, 32);
    }
    TransformComponent(int x, int y, int initSpeed){
        position.x = x; position.y = y; speed = initSpeed;
    }

    void update(double deltaTime) override{
        position.x += speed * deltaTime;
        position.y += speed * deltaTime;
    }
};
