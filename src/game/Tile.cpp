#include "game/Tile.h"

using namespace Game2D;

Tile::Tile(SDL_Texture* texture, int x, int y, int w, int h) : GE2D::Sprite(texture,x,y,w,h) {

}

void Tile::update(GE2D::Scene& scene){}
void Tile::handleEvent(SDL_Event& event){}