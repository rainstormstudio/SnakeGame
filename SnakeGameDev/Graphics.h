#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_mixer.h>
#elif _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
    #include <SDL_ttf.h>
    #include <SDL_mixer.h>
#endif
#include <string>

class Graphics{
public:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    const char* TITLE;
    Uint32 fullscreen;
    SDL_Window* window;
    static SDL_Renderer* renderer;

    Graphics(std::string title, int initWidth, int initHeight, Uint32 fullscreenFlag);
    ~Graphics();
    void clear();
    void render();
    static SDL_Texture* loadTexture(std::string fileName);
    static SDL_Texture* loadTexture(std::string fileName, SDL_Renderer* rendererName);
    static void drawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, double angle, SDL_Point center, SDL_RendererFlip flip);
    static void drawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, double angle, SDL_Point center, SDL_RendererFlip flip, SDL_Renderer* rendererName);
};
