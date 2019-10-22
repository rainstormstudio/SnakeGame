#pragma once
#include <SDL2/SDL.h>
#define KEY_TOTAL 1 << 30

class Keyboard{
private:
    bool prevKey[KEY_TOTAL];
    bool keyPressed[KEY_TOTAL];
    bool keyReleased[KEY_TOTAL];
    SDL_Event event;
public:
    bool quitSignal;

    Keyboard();
    ~Keyboard();
    bool isKeyPressed(int key);
    bool isKeyReleased(int key);
    void update();
};