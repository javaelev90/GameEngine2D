#include <iostream>
#include "GameObject.h"

unsigned long GameObject::nextID = 0;


GameObject::~GameObject() {
	delete GameObject::position;
}

GameObject::GameObject() {
	GameObject::_id = ++GameObject::nextID;
	GameObject::position = new Position();
	GameObject::position->x = 0;
	GameObject::position->y = 0;
};

GameObject::GameObject(int x, int y) {
	GameObject::_id = ++GameObject::nextID;
	GameObject::position = new Position();
	GameObject::position->x = x;
	GameObject::position->y = y;
}

long GameObject::getID() { 
	return _id;
}

Position& GameObject::getPosition() { 
	return *position;
}