#pragma once
#include "Graphics.h"
#include "Map.h"
#include "Keyboard.h"
#include "GameObject.h"

class Game{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int FPS;

    bool main_loop;

    Graphics* gfx;
    Map* map;
    Keyboard* keyboard;
    Player* player;

public:
    Game();
    ~Game();
    void update(double deltaTime);
    void render();
};
