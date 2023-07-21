#pragma once

#include <vector>

#include "entity/GameObject.h"
#include "entity/Sprite.h"
#include "engine/Utility.h"

namespace GE2D {

    class Scene {

        public:
            Scene();
            ~Scene();
            void update();
            
            void addGameObject(GameObject* gameObject);
            void addTileMapObject(Sprite* sprite);
            void removeGameObject(GameObject& gameObject);
            void removeTileMapObject(Sprite& sprite);

            inline std::vector<GameObject*> getGameObjects() { return gameObjects; };
            inline std::vector<Sprite*> getTileMapObjects(){ return tileMapObjects; };
            GameObject* getGameObject(unsigned long gameObjectId);
        private:
            std::vector<GameObject*> gameObjects;
            std::vector<Sprite*> tileMapObjects;
            
            // Temporary holders of objects, these are cleared each call to update() after
            // the values are inserted into the public gameobject/sprite vectors.
            // This is done to prevent issues occuring due to removing objects from the vector during iteration
            std::vector<GameObject*> _gameObjectsToAdd;
            std::vector<unsigned long> _gameObjectsToDelete;
            std::vector<Sprite*> _tileMapObjectsToAdd;
            std::vector<unsigned long> _tileMapObjectsToDelete;

            Scene(const Scene& other) = delete;
            const Scene& operator=(const Scene& other) = delete;


    };
}