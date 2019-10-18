#include "GameObject.h"

GameObject::GameObject(std::string textureSheet, SDL_Renderer* rendererName,
                       int initX, int initY, int initWidth, int initHeight, int scale){
    renderer = rendererName;
    objTexture = Graphics::loadTexture(textureSheet.c_str(), renderer);

    posX = initX;
    posY = initY;

    srcRect.w = initWidth;
    srcRect.h = initHeight;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.w = srcRect.w * scale;
    destRect.h = srcRect.h * scale;
    destRect.x = posX;
    destRect.y = posY;
}

GameObject::~GameObject(){}

void GameObject::update(){
    updatePos();
}

void GameObject::render(){
    SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void GameObject::updatePos(){
    destRect.x = posX;
    destRect.y = posY;
}
