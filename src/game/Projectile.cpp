#include <iostream>

#include "input/InputSystem.h"
#include "engine/GameEngine.h"
#include "engine/EventHandler.h"
#include "game/Projectile.h"
#include "game/Game.h"
#include "game/Enemy.h"
#include "entity/Sprite.h"

using namespace Game2D;

Projectile::Projectile(SDL_Texture* texture, int x, int y, int w, int h,
        GE2D::Vector2DInt* direction, std::vector<SpriteType> damagesSpriteTypes)
        : GE2D::Sprite(texture,x,y,w,h), _direction(direction), damagesSpriteTypes(damagesSpriteTypes) {
}
Projectile::~Projectile(){
    delete _direction;
}

void Projectile::update(GE2D::Scene& scene){
    float dx = _direction->x * GE2D::GameEngine::deltaTime * 800; 
    float dy = _direction->y * GE2D::GameEngine::deltaTime * 800; 
    _position->x += dx;
    _position->y += dy;
    _bounds.x = _position->x;
    _bounds.y = _position->y;
    // Check if colliding with tilemap
    for(Sprite* sprite : scene.getTileMapObjects()){
        SDL_Rect collision;
        bool collided = isColliding(*sprite, &collision);
        if(sprite->getType() == SpriteType::GROUND
                && collided) {
            scene.removeGameObject(*this);
            break;
        }
    }
    // Check if colliding with damageable object
    for(GameObject* obj : scene.getGameObjects()){
        DamageableSprite* sprite = dynamic_cast<DamageableSprite*>(obj);
        if(sprite != nullptr && sprite->getID() != getID()){
            SDL_Rect collision;
            bool collided = isColliding(*sprite, &collision);
            for(SpriteType type : damagesSpriteTypes){
                if (sprite->getType() == type && collided) {
                    // scene.removeGameObject(*sprite);
                    sprite->takeDamage(scene, 1);
                    scene.removeGameObject(*this);
                    return;
                }
            }
        }
    }
}

void Projectile::handleEvent(SDL_Event& event){
}
