#pragma once
#include <string>
#include <map>

#include "GameObject.h"

class Scene {
public:
	Scene();
	~Scene();
	void update();
	void addToScene(GameObject& gameObject);
	void removeFromScene(GameObject& gameObject);
	void printSceneGameObjects();
private:
	std::map<unsigned long,GameObject*>* gameObjects;

};