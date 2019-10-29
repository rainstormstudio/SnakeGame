#include "Map.h"
#include "Game.h"
#include <fstream>
#include "ECS/ECS.h"
#include "ECS/Components.h"
extern Manager manager;

Map::Map(std::string mfp, int ms, int ts){
    mapFilePath = mfp;
    mapScale = ms;
    tileSize = ts;
    scaledSize = ms * ts;
}

Map::~Map(){
}

void Map::loadMap(std::string path, int sizeX, int sizeY){
    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    int srcX, srcY, theta;

    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            mapFile.get(tile);
            srcY = atoi(&tile) * tileSize;
            mapFile.get(tile);
            srcX = atoi(&tile) * tileSize;
            mapFile.get(tile);
            theta = atoi(&tile) * 90;
            addTile(srcX, srcY, x * scaledSize, y * scaledSize, theta);
            mapFile.ignore();
        }
    }
    mapFile.ignore();
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            mapFile.get(tile);
            if (tile == '1'){
                auto& tileCollider(manager.addEntity());
                tileCollider.addComponent<ColliderComponent>("map", x * scaledSize, y * scaledSize, scaledSize);
                tileCollider.addGroup(Game::groupColliders);
            }
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::addTile(int srcX, int srcY, int posX, int posY, int theta){
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(srcX, srcY, posX, posY, theta, tileSize, mapScale, mapFilePath);
    tile.addGroup(Game::groupMap);
}