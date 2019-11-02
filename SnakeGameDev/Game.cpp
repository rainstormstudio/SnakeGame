#include "Game.h"
#include "ECS/Components.h"
#include "AssetsManager.h"
#include "Map.h"
#include "Vector2D.h"
#include "Collision.h"

Manager manager;
SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 800, 640};
AssetManager* Game::assets = new AssetManager(&manager);
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Map* map;

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupPlayers));

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

    assets->addTexture("map", "assets/map.png");
    assets->addTexture("player", "assets/player-anim.png");
    assets->addTexture("projectile", "assets/projectile.png");

    map = new Map("map", 2, 32);
    map->loadMap("levels/level.map", 25, 20);
    printf("map initialized\n");
    player.addComponent<TransformComponent>(400, 320, 64 * 2, 32, 32, 2);
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardController>();
    player.addGroup(groupPlayers);
    printf("player initialized\n");
    assets->createProjectile(Vector2D(10, 10), 200, 96, "projectile");
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
        //printf("====================================================\n");
    }
    printf("the while loop is over");
}

Game::~Game(){}

void Game::update(double deltaTime){
    SDL_Rect playerCollider = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPosition = player.getComponent<TransformComponent>().position;

    manager.refresh();
    manager.update(deltaTime);

    for (auto& c : colliders){
        SDL_Rect cCollider = c->getComponent<ColliderComponent>().collider;
        if (Collision::AABBbox(cCollider, playerCollider)){
            player.getComponent<TransformComponent>().position = playerPosition;
        }
    }
/*
    for (auto& p : projectiles){
        if (Collision::AABBbox(player.getComponent<ColliderComponent>().collider,
        p->getComponent<ColliderComponent>().collider)){
            printf("hit player!\n");
            p->destroy();
        }
    }
*/
    camera.x = player.getComponent<TransformComponent>().position.x - 400;
    camera.y = player.getComponent<TransformComponent>().position.y - 320;

    if (camera.x < 0) camera.x = 0;
    if (camera.y < 0) camera.y = 0;
    if (camera.x > camera.w) camera.x = camera.w;
    if (camera.y > camera.h) camera.y = camera.h;
}

void Game::render(){
    gfx->clear();
    for (auto& tile : tiles){
        tile->draw();
    }
    for (auto& collider : colliders){
        collider->draw();
    }
    for (auto& play : players){
        play->draw();
    }
    for (auto& enemy : enemies){
        enemy->draw();
    }
    for (auto& p : projectiles){
        p->draw();
    }
    gfx->render();
}
