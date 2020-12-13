#include <iostream>
#include "Sprite.h"

void Sprite::update() {
	
	std::cout << "Object   : " << "x: " << getPosition().x << " y: " << getPosition().y << std::endl;
	
}