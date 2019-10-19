#include "Keyboard.h"

Keyboard::Keyboard(){
    for (int i = 0; i < KEY_TOTAL; i++){
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
            keyPressed[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            keyPressed[event.key.keysym.sym] = false;
            break;
        }
    }
}
