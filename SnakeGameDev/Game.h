#pragma once
#include "Graphics.h"
#include <vector>

class ColliderComponent;

class Game{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int FPS;

    Graphics* gfx;

    bool main_loop;

public:
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;

    Game();
    ~Game();
    void update(double deltaTime);
    void render();
    static void addTile(int srcX, int srcY, int posX, int posY, int theta);
};
