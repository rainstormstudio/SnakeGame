#include "Game.h"

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 600;
    FPS = 60;
    int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    gfx = new Graphics("SnakeGame", SCREEN_WIDTH, SCREEN_HEIGHT);

    player = new GameObject("assets/player.png", gfx->renderer, 0, 0, 32, 32, 2);
    main_loop = true;
    while (main_loop){
        frameStart = SDL_GetTicks();

        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

Game::~Game(){}

void Game::update(){
    player->update();
}

void Game::render(){
    gfx->clear();
    player->render();
    gfx->render();
}
