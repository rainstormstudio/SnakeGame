#include "Game.h"

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 600;
    FPS = 60;
    int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    gfx = new Graphics("SnakeGame", SCREEN_WIDTH, SCREEN_HEIGHT);

    main_loop = true;
    playerTexture = gfx->loadTexture("assets/player.png", gfx->renderer);
    rect.h = 64;
    rect.w = 64;
    rect.x = 0;
    rect.y = 0;
    temp = 0;

    while (main_loop){
        frameStart = SDL_GetTicks();

        update(0);
        render(0);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

Game::~Game(){}

void Game::update(double deltaTime){
    temp ++;
    rect.x = temp;
}

void Game::render(double deltaTime){
    gfx->clear();
    SDL_RenderCopy(gfx->renderer, playerTexture, NULL, &rect);
    gfx->render();
}
