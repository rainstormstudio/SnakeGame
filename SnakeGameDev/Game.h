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
    static SDL_Rect camera;
    enum groupLabels : std::size_t{
        groupMap,
        groupPlayers,
        groupEnemies,
        groupColliders
    };

    Game();
    ~Game();
    void update(double deltaTime);
    void render();
};
