#include <iostream>
#include <time.h>

#include "input/InputSystem.h"
#include "engine/GameEngine.h"
#include "engine/EventHandler.h"
#include "game/Enemy.h"
#include "game/Game.h"
#include "game/Projectile.h"
#include "entity/Sprite.h"
#include "game/DamageableSprite.h"

using namespace Game2D;

float Enemy::xDirection = 0;
float Enemy::yLevel = 0;

Enemy::Enemy(SDL_Texture* texture, int x, int y, int w, int h) : DamageableSprite(texture,x,y,w,h) {
    xDirection = 1;
    srand(time(NULL));
    startPosition = new GE2D::Vector2DInt();
    startPosition->x = x;
    startPosition->y = y;
}
Enemy::~Enemy(){
    delete startPosition;
}

void Enemy::update(GE2D::Scene& scene){
    float dx = xDirection * GE2D::GameEngine::deltaTime * 240; 

    changePosition(dx, yLevel);
    // Check if colliding with tilemap
    for(GameObject* obj : scene.getTileMapObjects()){
        Sprite* sprite = dynamic_cast<Sprite*>(obj);
        if(sprite->getID()!= getID()){
            SDL_Rect collision;
            // When colliding with wall move down 20 pixels and change direction
            if(sprite->getType() == SpriteType::GROUND && isColliding(*sprite, &collision)) {
                yLevel += 20;
                changePosition(-dx, yLevel);
                changeDirection();
                break;
            }
        }
    }
    if((rand() % 600 + 1) == 5){
        GE2D::Vector2DInt* direction = new GE2D::Vector2DInt();
        direction->x = 0;
        direction->y = 1;
        // Add projectile to scene with downwards movement, damages player
        scene.addGameObject(new Projectile(Game::getTexture(SpriteType::PROJECTILE),
                (_position->x + _bounds.w / 2), (_position->y + _bounds.h), _bounds.w / 2, _bounds.h / 2,
                direction, std::vector<SpriteType>{SpriteType::PLAYER}));        
    }
}

void Enemy::handleEvent(SDL_Event& event){
}

void Enemy::changeDirection(){
    xDirection *= -1;
}

void Enemy::changePosition(float dx, float dy) {
    _position->x += dx;
    _position->y = startPosition->y + dy;
    _bounds.x = _position->x;
    _bounds.y = _position->y;
}

void Enemy::takeDamage(GE2D::Scene& scene, float damage){
    scene.removeGameObject(*this);
}