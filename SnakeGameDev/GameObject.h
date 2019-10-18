#pragma once
#include "Graphics.h"

class GameObject{
private:
    int posX, posY;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
public:
    GameObject(std::string textureSheet, SDL_Renderer* rendererName,
               int initX, int initY, int initWidth, int initHeight, int scale);
    ~GameObject();
    void update();
    void render();
    void updatePos();
};
