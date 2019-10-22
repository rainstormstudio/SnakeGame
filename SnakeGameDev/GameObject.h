#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class GameObject{
private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
public:
    double posX, posY;
    double speed;
    GameObject(std::string textureSheet, SDL_Renderer* rendererName,
               int initX, int initY, int initWidth, int initHeight, int scale,
               int initSpeed);
    ~GameObject();
    void update(double deltaTime);
    void render();
    void updatePos();
};

class Player: public GameObject{
    using GameObject::GameObject;
public:
    void update(Keyboard* keyboard, double deltaTime);
};
