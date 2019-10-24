#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component{
private:
    double speed;
public:
    Vector2D position;
    Vector2D velocity;

    int width;
    int height;
    int scale;

    TransformComponent(){
        TransformComponent(0, 0, 32, 32, 32, 1);
    }
    TransformComponent(int x, int y, int initSpeed,
                       int initWidth, int initHeight, int initScale){
        position.x = x; position.y = y; speed = initSpeed;
        width = initWidth; height = initHeight; scale = initScale;
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
