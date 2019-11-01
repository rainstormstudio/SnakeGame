#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component{
public:
    double speed;
    Vector2D position;
    Vector2D velocity;

    int width;
    int height;
    int scale;
    double angle;

    TransformComponent(){
        position.x = 0; position.y = 0; speed = 32;
        width = 32; height = 32; scale = 1;
        angle = 0.0f;
    }
    TransformComponent(int x, int y, int initSpeed,
                       int initWidth, int initHeight, int initScale){
        position.x = x; position.y = y; speed = initSpeed;
        width = initWidth; height = initHeight; scale = initScale;
        angle = 0.0f;
    }

    void init() override{
        velocity.zero();
    }

    void update(double deltaTime) override{
        position.x += velocity.x * speed * deltaTime;
        position.y += velocity.y * speed * deltaTime;
    }
};
