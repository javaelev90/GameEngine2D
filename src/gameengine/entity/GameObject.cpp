#include <iostream>

#include "entity/GameObject.h"
#include "engine/Scene.h"

using namespace GE2D;

unsigned long GameObject::nextID = 0;

GameObject::GameObject(){
    _id = ++GameObject::nextID;
	_position = new Vector2D();
	_position->x = 0;
	_position->y = 0;
}
GameObject::GameObject(float x, float y){
    _id = ++GameObject::nextID;
	_position = new Vector2D();
	_position->x = x;
	_position->y = y;
}
GameObject::~GameObject(){
    delete _position;
}
