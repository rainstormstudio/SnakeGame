#pragma once
#include "Graphics.h"

class Game{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int FPS;

    Graphics* gfx;

    bool main_loop;

public:
    static SDL_Event event;

    Game();
    ~Game();
    void update(double deltaTime);
    void render();
    void handleEvents();
};
