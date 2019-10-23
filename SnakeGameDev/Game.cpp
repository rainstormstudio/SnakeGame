#include "Game.h"

Manager manager;
auto& player(manager.addEntity());
Graphics* gfx;

Map* map;
Keyboard* keyboard;

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 640;
    FPS = 120;
    double frameDelay = 1000 / FPS;
    Uint32 frameA;
    Uint32 frameB;
    Uint32 frameTime;
    Uint32 sleepTime;

    gfx = new Graphics("SnakeGame", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    printf("graphics initialized\n");
    player.addComponent<TransformComponent>(64, 64, 32);
    player.addComponent<SpriteComponent>("assets/player.png", gfx->renderer);

    map = new Map(gfx->renderer);
    printf("map initialized\n");
    keyboard = new Keyboard();
    printf("keyboard initialized\n");
    printf("player initialized\n");
    printf("========================================\n");

    frameA = SDL_GetTicks();
    main_loop = true;
    while (main_loop){
        frameB = SDL_GetTicks();
        frameTime = frameB - frameA;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        frameA = SDL_GetTicks();
        sleepTime = frameA - frameB;

        update((frameTime + sleepTime) / 1000.0f);
        render();

        if (keyboard->quitSignal) main_loop = false;

        printf(" FPS: %.3f\n", (1000.0f / (frameTime + sleepTime)));
    }
    printf("the while loop is over");
}

Game::~Game(){}

void Game::update(double deltaTime){
    keyboard->update();
    manager.refresh();
    manager.update(deltaTime);
}

void Game::render(){
    gfx->clear();
    map->drawMap();
    manager.draw(gfx->renderer);
    gfx->render();
}
