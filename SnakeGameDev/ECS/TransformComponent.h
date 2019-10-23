#pragma once
#include "Components.h"

class TransformComponent : public Component{
private:
    double posX, posY;
    double speed;
public:
    TransformComponent(){
        posX = posY = 0;
        speed = 32;
    }
    TransformComponent(int x, int y, int initSpeed){
        posX = x; posY = y; speed = initSpeed;
    }
    int x(){ return posX;}

    int y(){ return posY;}

    void init() override{
        posX = 0; posY = 0;
    }

    void update(double deltaTime) override{
        posX += speed * deltaTime;
        posY += speed * deltaTime;
    }

    void setPosition(int x, int y){
        posX = x; posY = y;
    }
};
