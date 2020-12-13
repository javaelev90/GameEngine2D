#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Scene.h"

#include "Sprite.h"
int main(int argc, char** argv) {

	Scene* scene = new Scene();

	//GameObject* gameObject = new GameObject(1,2);
	//GameObject* gameObject2 = new GameObject(3,4);
	Sprite* sprite = new Sprite();
	scene->addToScene(*sprite);
	//Sprite* sprite = new Sprite(5,7);
	//scene->addToScene(*sprite);
	scene->printSceneGameObjects();
	//scene->removeFromScene();

	//scene->printSceneGameObjects();

	delete scene;
	
	_CrtDumpMemoryLeaks();
	return 0;
}