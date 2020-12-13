#include <iostream>
#include <cstdint>
#include "Scene.h"
#include "GameObject.h"

using namespace std;

Scene::Scene() {
	gameObjects = new map<unsigned long, GameObject*>;
}

Scene::~Scene() {
	delete gameObjects;
}

void Scene::update() {
	
}

void Scene::printSceneGameObjects() {
	for (std::map<unsigned long, GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		it->second->update();
	}
}

void Scene::addToScene(GameObject& gameObject) {
	cout << gameObject.getID() << endl;
	gameObjects->insert(std::make_pair(gameObject.getID(),&gameObject));
}

void Scene::removeFromScene(GameObject& gameObject) {
	gameObjects->erase(gameObject.getID());
}