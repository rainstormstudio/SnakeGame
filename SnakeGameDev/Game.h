#pragma once
#include "Graphics.h"
#include <vector>

class AssetManager;
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
    static AssetManager* assets;
    enum groupLabels : std::size_t{
        groupMap,
        groupPlayers,
        groupEnemies,
        groupColliders,
        groupProjectiles
    };

    Game();
    ~Game();
    void update(double deltaTime);
    void render();
};
