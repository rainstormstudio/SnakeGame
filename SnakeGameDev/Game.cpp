#include "Game.h"

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 600;

    gfx = new Graphics("SnakeGame", SCREEN_WIDTH, SCREEN_HEIGHT);

    main_loop = true;
    playerTexture = gfx->loadTexture("assets/player.png", gfx->renderer);
    while (main_loop){

        update(0);
        render(0);
    }
}

Game::~Game(){}

void Game::update(double deltaTime){

}

void Game::render(double deltaTime){
    gfx->clear();
    gfx->render();
}
