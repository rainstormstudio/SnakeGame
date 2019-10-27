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

Map* map;

enum groupLabels : std::size_t{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};

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
    Map::loadMap("levels/level.map", 25, 20);
    printf("map initialized\n");
    player.addComponent<TransformComponent>(64, 64, 64, 32, 32, 2);
    player.addComponent<SpriteComponent>("assets/player-idle.png", 4, 150);
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardController>();
    player.addGroup(groupPlayers);
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


        if (event.type == SDL_QUIT)
            main_loop = false;

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

    for (auto cc : colliders){
        Collision::AABBbox(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));
void Game::render(){
    gfx->clear();
    for (auto& tile : tiles){
        tile->draw();
    }
    for (auto& play : players){
        play->draw();
    }
    for (auto& enemy : enemies){
        enemy->draw();
    }
    gfx->render();
}

void Game::addTile(int id, int x, int y){
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupMap);
}
