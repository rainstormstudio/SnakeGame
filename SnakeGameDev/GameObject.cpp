#include "GameObject.h"

GameObject::GameObject(std::string textureSheet, SDL_Renderer* rendererName,
                       int initX, int initY, int initWidth, int initHeight, int scale,
                       int initSpeed){
    renderer = rendererName;
    objTexture = Graphics::loadTexture(textureSheet.c_str(), renderer);

    orientation = FRONT_ORIENTATION;
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
    switch (orientation){
        case FRONT_ORIENTATION: srcRect.x = 0; srcRect.y = 0; break;
        case BACK_ORIENTATION: srcRect.x = 33; srcRect.y = 0; break;
        case LEFT_ORIENTATION: srcRect.x = 33; srcRect.y = 33; break;
        case RIGHT_ORIENTATION: srcRect.x = 0; srcRect.y = 33; break;
    }
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void GameObject::updatePos(){
    if ((int)round(posX) % 32 == 0) destRect.x = round(posX);
    if ((int)round(posY) % 32 == 0) destRect.y = round(posY);
    //destRect.x = (int)round(posX);
    //destRect.y = (int)round(posY);
}

void Player::update(Keyboard* keyboard, double deltaTime){
    if (keyboard->isKeyPressed(SDLK_a)){
        orientation = LEFT_ORIENTATION;
        posX -= speed * deltaTime;
    }
    if (keyboard->isKeyPressed(SDLK_d)){
        orientation = RIGHT_ORIENTATION;
        posX += speed * deltaTime;
    }
    if (keyboard->isKeyPressed(SDLK_w)){
        orientation = BACK_ORIENTATION;
        posY -= speed * deltaTime;
    }
    if (keyboard->isKeyPressed(SDLK_s)){
        orientation = FRONT_ORIENTATION;
        posY += speed * deltaTime;
    }
    updatePos();
}
