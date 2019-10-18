#pragma once
#include "Graphics.h"

class Game{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int FPS;

    bool main_loop;

    Graphics* gfx;

    SDL_Texture* playerTexture;
    SDL_Rect rect;
    int temp;
public:
    Game();
    ~Game();
    void update(double deltaTime);
    void render(double deltaTime);
};
