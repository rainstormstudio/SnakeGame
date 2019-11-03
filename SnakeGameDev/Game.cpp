#include "Game.h"
#include "ECS/Components.h"
#include "AssetsManager.h"
#include "Map.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 800, 640};
AssetManager* Game::assets = new AssetManager(&manager);

auto& player(manager.addEntity());

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));

Game::Game(){
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 640;
    FPS = 30;
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
    printf("player at %p\n", &player);
    assets->createProjectile(Vector2D(10, 10), Vector2D(1, 0), 300, 32, "projectile");
    printf("========================================\n");

    frameA = SDL_GetTicks();
    main_loop = true;
    while (main_loop){
        printf("====================================================\n");
        printf("main loop start >>>>>>>>>>>\n");
        frameB = SDL_GetTicks();
        frameTime = frameB - frameA;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        frameA = SDL_GetTicks();
        sleepTime = frameA - frameB;


        if (event.type == SDL_QUIT)
            main_loop = false;

        printf("start update\n");
        update((frameTime + sleepTime) / 1000.0f);
        printf("update complete\n");
        printf("start render\n");
        render();
        printf("render complete\n");

        printf(" FPS: %.3f\n", (1000.0f / (frameTime + sleepTime)));
        printf("main loop end <<<<<<<<<<<<<\n");
        printf("====================================================\n\n");
    }
    printf("the while loop is over");
}

Game::~Game(){
    SDL_Quit();
}

void Game::update(double deltaTime){
    printf("update initialing ... \n");
    SDL_Rect playerCollider = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPosition = player.getComponent<TransformComponent>().position;
    printf("update initialing done \n");
    manager.refresh();
    printf("manager refreshed\n");
    manager.update(deltaTime);
    printf("manager updated\n");

    for (auto& c : colliders){
        SDL_Rect cCollider = c->getComponent<ColliderComponent>().collider;
        if (Collision::AABBbox(cCollider, playerCollider)){
            player.getComponent<TransformComponent>().position = playerPosition;
        }
    }
    printf("collider checked\n");

    for (auto& p : projectiles){
        if (Collision::AABBbox(player.getComponent<ColliderComponent>().collider,
        p->getComponent<ColliderComponent>().collider)){
            printf("hit player!\n");
            printf("destroy p at %p\n", p);
            p->destroy();
        }
    }
    printf("projectiles checked\n");

    camera.x = static_cast<int>(player.getComponent<TransformComponent>().position.x - 400);
    camera.y = static_cast<int>(player.getComponent<TransformComponent>().position.y - 320);

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
    for (auto& coll : colliders){
        coll->draw();
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
