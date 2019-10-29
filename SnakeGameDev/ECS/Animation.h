#pragma once

struct Animation{
    int index;
    int frames;
    int speed;

    Animation(){}
    Animation(int initIndex, int initFrames, int initSpeed){
        index = initIndex;
        frames = initFrames;
        speed = initSpeed;
    }
};