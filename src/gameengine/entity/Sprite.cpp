#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

#include "entity/Sprite.h"
#include "rendering/Renderer.h"

using namespace GE2D;

Sprite::Sprite(SDL_Texture* texture) : GameObject(0,0) {
	_texture = texture;

	_bounds.x = 0;
	_bounds.y = 0;
	_bounds.w = 0;
	_bounds.h = 0;
}

Sprite::~Sprite() {
}

Sprite::Sprite(SDL_Texture* texture, int x, int y, int w, int h) : GameObject(x,y) {
	_texture = texture;

	_bounds.x = x;
	_bounds.y = y;
	_bounds.w = w;
	_bounds.h = h;
}

void Sprite::draw(Renderer* renderer){

	SDL_Rect dst;
    dst.x = _position->x;
    dst.y = _position->y;
    dst.w = _bounds.w;
    dst.h = _bounds.h;
	_bounds.x = _position->x;
	_bounds.y = _position->y;
	renderer->render(_texture, dst);
}

bool Sprite::isColliding(Sprite& other, SDL_Rect* result){

	if(SDL_HasIntersection(getBounds(), other.getBounds())) {
		SDL_IntersectRect(getBounds(), other.getBounds(), result);
		return true;
	}
	return false;
}
