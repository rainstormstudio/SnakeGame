#include "Graphics.h"

Graphics::Graphics(std::string title, int initWidth, int initHeight){
    SCREEN_WIDTH = initWidth;
    SCREEN_HEIGHT = initHeight;
    TITLE = title.c_str();

    // initialize windows
    window = NULL;
    renderer = NULL;

    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else{
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL){
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else{
            renderer = SDL_CreateRenderer(window, -1, 0);
            SDL_SetRenderDrawColor(renderer, 0, 50, 100, 255);
            clear();
            render();
        }
    }
}

Graphics::~Graphics(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Graphics::clear(){
    SDL_RenderClear(renderer);
}

void Graphics::render(){
    SDL_RenderPresent(renderer);
}

SDL_Texture* Graphics::loadTexture(std::string fileName, SDL_Renderer* rendererName){
    return IMG_LoadTexture(rendererName, fileName.c_str());
}

void Graphics::drawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, double angle, SDL_Point center, SDL_RendererFlip flip, SDL_Renderer* rendererName){
    SDL_RenderCopyEx(rendererName, texture, &srcRect, &destRect, angle, &center, flip);
}
