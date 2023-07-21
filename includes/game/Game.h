#pragma once
#include <vector>
#include <map>
#include "engine/Scene.h"
#include "rendering/Renderer.h"

namespace Game2D {

    enum SpriteType {
        EMPTY = 0,
        GROUND = 1,
        ENEMY = 2,
        PROJECTILE = 3,
        PLAYER = 4,
        DEFENSE = 5,
        BOUNDARY = 6
    };

    class Game {

        public:
            Game(std::string imgPath);
            ~Game();
            GE2D::Scene* loadMap(std::vector<std::vector<int>> map, int tileSizeX, int tileSizeY, GE2D::Renderer& renderer);
            void loadTextures(GE2D::Renderer& renderer);
            static SDL_Texture* getTexture(SpriteType spriteType);
        private:
            static std::map<SpriteType, SDL_Texture*> textures;
            std::string imagePath = "./images/";
    };

}