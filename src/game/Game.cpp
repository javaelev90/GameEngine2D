#include "game/Game.h"
#include "game/Tile.h"
#include "game/Enemy.h"
#include "game/Player.h"
#include "rendering/Renderer.h"

using namespace Game2D;

std::map<SpriteType, SDL_Texture*> Game::textures;

Game::Game(std::string imgPath): imagePath(imgPath){
}

Game::~Game() {
    for(auto& pair : textures) {
        SDL_DestroyTexture(pair.second);
        pair.second = nullptr;
    }
}

// Loads textures into a map so that they can be used by multiple sprites
void Game::loadTextures(GE2D::Renderer& renderer){
    textures[SpriteType::PLAYER] = renderer.loadTexture(imagePath + "tank.png");
    textures[SpriteType::GROUND] = renderer.loadTexture(imagePath + "ground.png");
    textures[SpriteType::PROJECTILE] = renderer.loadTexture(imagePath + "laser.png");
    textures[SpriteType::ENEMY] = renderer.loadTexture(imagePath + "alien.png");
    textures[SpriteType::BOUNDARY] = renderer.loadTexture(imagePath + "boundary.png");
}

SDL_Texture* Game::getTexture(SpriteType spriteType){
    return textures[spriteType];
}

// Adds Sprites to the window based on values from a 2D vector grid,
// depending on the grid elements value a certain sprite is created
GE2D::Scene* Game::loadMap(std::vector<std::vector<int>> map, int tileSizeX, int tileSizeY, GE2D::Renderer& renderer){
    GE2D::Scene* scene = new GE2D::Scene();

    for(size_t x = 0; x < map.at(0).size(); x++) {
        for(size_t y = 0; y < map.size(); y++) {
            int spriteType = map[y][x];
            Tile* tile = nullptr;
            Enemy* enemy = nullptr;
            Player* player = nullptr;
            switch(spriteType) {
                case SpriteType::GROUND:
                    tile = new Tile(textures[SpriteType::GROUND], tileSizeX * x, tileSizeY * y, tileSizeX, tileSizeY);
                    tile->setType(SpriteType::GROUND);
                    scene->addTileMapObject(tile);
                    break;
                case SpriteType::ENEMY:
                    enemy = new Enemy(textures[SpriteType::ENEMY], tileSizeX * x, tileSizeY * y, tileSizeX, tileSizeY);
                    enemy->setType(SpriteType::ENEMY);
                    scene->addGameObject(enemy);
                    break;
                case SpriteType::EMPTY:
                    break;
                case SpriteType::PLAYER:
                    player = new Player(textures[SpriteType::PLAYER], tileSizeX * x, tileSizeY * y, tileSizeX, tileSizeY);
                    player->setType(SpriteType::PLAYER);
                    scene->addGameObject(player);
                    break;
                case SpriteType::DEFENSE:
                    scene->addTileMapObject(new Tile(textures[SpriteType::GROUND], tileSizeX * x, tileSizeY * y, tileSizeX, tileSizeY));
                    break;
                case SpriteType::BOUNDARY:
                    tile = new Tile(textures[SpriteType::BOUNDARY], tileSizeX * x, tileSizeY * y, tileSizeX, tileSizeY);
                    tile->setType(SpriteType::GROUND);
                    scene->addTileMapObject(tile);
                    break;
                default:
                    break;
            }
        }
    }
    return scene;
}