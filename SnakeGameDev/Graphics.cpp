#include "Graphics.h"

Graphics::Graphics(std::string title, int initWidth, int initHeight){
    SCREEN_WIDTH = initWidth;
    SCREEN_HEIGHT = initHeight;
    TITLE = title.c_str();

    // initialize windows
    window = NULL;
    screenSurface = NULL;

    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else{
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL){
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else{
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
        }
    }
}

Graphics::~Graphics(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::clear(){
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
}

void Graphics::render(){
    SDL_UpdateWindowSurface(window);
}