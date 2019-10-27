#include "Game.h"
#include "ECS/Components.h"
#include "Map.h"
#include "Vector2D.h"
#include "Collision.h"

Manager manager;
SDL_Event Game::event;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());
std::vector<ColliderComponent*> Game::colliders;
auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

Map* map;

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
    player.addComponent<TransformComponent>(64, 64, 64, 32, 32, 1);
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardController>();

    wall.addComponent<TransformComponent>(300, 300, 32, 300, 20, 1);
    wall.addComponent<SpriteComponent>("assets/border.png");
    wall.addComponent<ColliderComponent>("wall");

    tile0.addComponent<TileComponent>(200, 200, 32, 32, DIRT);
    tile0.addComponent<ColliderComponent>("dirt");
    tile1.addComponent<TileComponent>(250, 250, 32, 32, GRASS);
    tile2.addComponent<TileComponent>(150, 150, 32, 32, BORDER_UP);
    tile2.addComponent<ColliderComponent>("border");

    //map = new Map();
    printf("map initialized\n");
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

        // printf(" FPS: %.3f\n", (1000.0f / (frameTime + sleepTime)));
    }
    printf("the while loop is over");
}

Game::~Game(){}

void Game::update(double deltaTime){
    manager.refresh();
    manager.update(deltaTime);
    handleEvents();

    for (auto cc : colliders){
        Collision::AABBbox(player.getComponent<ColliderComponent>(), *cc);
    }
}

void Game::render(){
    gfx->clear();
    //map->drawMap();
    manager.draw();
    gfx->render();
}

void Game::handleEvents(){
    if (event.type == SDL_QUIT)
        main_loop = false;
}
