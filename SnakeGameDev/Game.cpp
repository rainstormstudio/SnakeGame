#include "Game.h"

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 600;
    FPS = 60;
    double frameDelay = 1000 / FPS;
    Uint32 frameA;
    Uint32 frameB;
    Uint32 frameTime;
    Uint32 sleepTime;

    gfx = new Graphics("SnakeGame", SCREEN_WIDTH, SCREEN_HEIGHT);
    keyboard = new Keyboard();

    player = new Player("assets/player.png", gfx->renderer,
                        0, 0, 32, 32, 2, 64);

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
    player->update(keyboard, deltaTime);
}

void Game::render(){
    gfx->clear();
    player->render();
    gfx->render();
}
