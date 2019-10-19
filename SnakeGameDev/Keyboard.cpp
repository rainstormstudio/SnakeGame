#include "Keyboard.h"

Keyboard::Keyboard(){
    for (int i = 0; i < KEY_TOTAL; i++){
        prevKey[i] = false;
        keyPressed[i] = false;
        keyReleased[i] = false;
    }
    quitSignal = false;
    update();
}

Keyboard::~Keyboard(){}

bool Keyboard::isKeyPressed(int key){
return keyPressed[key];
}

bool Keyboard::isKeyReleased(int key){
return keyReleased[key];
}

void Keyboard::update(){
    while (SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            quitSignal = true;
            break;
        case SDL_KEYDOWN:
            prevKey[event.key.keysym.sym] = keyPressed[event.key.keysym.sym];
            keyPressed[event.key.keysym.sym] = true;
            keyReleased[event.key.keysym.sym] = false;
            break;
        case SDL_KEYUP:
            prevKey[event.key.keysym.sym] = keyPressed[event.key.keysym.sym];
            keyPressed[event.key.keysym.sym] = false;
            keyReleased[event.key.keysym.sym] = prevKey[event.key.keysym.sym];
            break;
        }
    }
}
