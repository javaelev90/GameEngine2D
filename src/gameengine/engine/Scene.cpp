#include <algorithm>
#include "engine/Scene.h"
#include "engine/Utility.h"

using namespace GE2D;

Scene::Scene(){
}

Scene::~Scene(){
    for(GameObject* obj : gameObjects){
        delete obj;
    }
    for(GameObject* obj : tileMapObjects){
        delete obj;
    }
}

void Scene::addGameObject(GameObject* gameObject){
    _gameObjectsToAdd.push_back(gameObject);
}

void Scene::addTileMapObject(Sprite* sprite) {
    _tileMapObjectsToAdd.push_back(sprite);
}

void Scene::removeGameObject(GameObject& gameObject){
    _gameObjectsToDelete.push_back(gameObject.getID());
  
}

void Scene::removeTileMapObject(Sprite& sprite){
    _tileMapObjectsToDelete.push_back(sprite.getID());
}

void Scene::update(){

    for(size_t i = 0; i < gameObjects.size(); i++){
        gameObjects.at(i)->update(*this);
    }

    // Add new objects to scene
    gameObjects.insert(gameObjects.end(), _gameObjectsToAdd.begin(), _gameObjectsToAdd.end());
    _gameObjectsToAdd.clear();

    tileMapObjects.insert(tileMapObjects.end(), _tileMapObjectsToAdd.begin(), _tileMapObjectsToAdd.end());
    _tileMapObjectsToAdd.clear();

    // Remove objects that were removed from the scene
    for(unsigned long objectId : _gameObjectsToDelete){
        deleteGameObjectFromVectorUsingId<GameObject>(gameObjects, objectId);
    }
    _gameObjectsToDelete.clear();
    for(unsigned long objectId : _tileMapObjectsToDelete){
        deleteGameObjectFromVectorUsingId<Sprite>(tileMapObjects, objectId);
    }
    _tileMapObjectsToDelete.clear();
}
