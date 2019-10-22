#include "GameObject.h"

GameObject::GameObject(std::string textureSheet, SDL_Renderer* rendererName,
                       int initX, int initY, int initWidth, int initHeight, int scale,
                       int initSpeed){
    renderer = rendererName;
    objTexture = Graphics::loadTexture(textureSheet.c_str(), renderer);

    posX = initX;
    posY = initY;
    speed = initSpeed;

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

void GameObject::update(double deltaTime){
    updatePos();
}

void GameObject::render(){
    SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void GameObject::updatePos(){
    if ((int)round(posX) % 32 == 0) destRect.x = round(posX);
    if ((int)round(posY) % 32 == 0) destRect.y = round(posY);
    //destRect.x = (int)round(posX);
    //destRect.y = (int)round(posY);
}

void Player::update(Keyboard* keyboard, double deltaTime){
    if (keyboard->isKeyPressed(SDLK_a))
        posX -= speed * deltaTime;
    if (keyboard->isKeyPressed(SDLK_d))
        posX += speed * deltaTime;
    if (keyboard->isKeyPressed(SDLK_w))
        posY -= speed * deltaTime;
    if (keyboard->isKeyPressed(SDLK_s))
        posY += speed * deltaTime;
    updatePos();
}
