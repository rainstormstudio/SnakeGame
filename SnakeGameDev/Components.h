#pragma once
#include "ECS.h"

class TransformComponent : public Component{
private:
    int posX, posY;
public:
    int x(){
        return posX;
    }

    int y(){
        return posY;
    }

    void init() override{
        posX = 0; posY = 0;
    }

    void update() override{
        posX ++;
        posY ++;
    }

    void setPosition(int x, int y){
        posX = x; posY = y;
    }
};