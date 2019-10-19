#include "Game.h"

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 600;
    FPS = 60;
    int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    gfx = new Graphics("SnakeGame", SCREEN_WIDTH, SCREEN_HEIGHT);
    keyboard = new Keyboard();

    player = new Player("assets/player.png", gfx->renderer,
                        0, 0, 32, 32, 2, 32);
    main_loop = true;
    while (main_loop){
        frameStart = SDL_GetTicks();

        update(frameTime / 1000.0f);
        render();

        if (keyboard->quitSignal) main_loop = false;

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
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
