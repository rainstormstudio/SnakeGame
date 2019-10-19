#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "GameObject.h"

class Game{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int FPS;

    bool main_loop;

    Graphics* gfx;
    Keyboard* keyboard;
    GameObject* player;

public:
    Game();
    ~Game();
    void update();
    void render();
};
