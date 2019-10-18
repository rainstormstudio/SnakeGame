#pragma once
#include "Graphics.h"

class Game{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;

    Graphics* gfx;
public:
    Game();
    ~Game();
    void update(double deltaTime);
    void render(double deltaTime);
};
