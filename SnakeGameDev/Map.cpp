#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map(){

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
            srcY = atoi(&tile) * 32;
            mapFile.get(tile);
            srcX = atoi(&tile) * 32;
            mapFile.get(tile);
            theta = atoi(&tile) * 90;
            Game::addTile(srcX, srcY, x * 32 * 2, y * 32 * 2, theta);
            mapFile.ignore();
        }
    }

    mapFile.close();
}
