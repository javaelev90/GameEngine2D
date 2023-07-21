#include <iostream>

#include "input/InputSystem.h"
#include "engine/GameEngine.h"
#include "engine/EventHandler.h"
#include "game/Player.h"
#include "game/Game.h"
#include "game/Projectile.h"
#include "game/DamageAbleSprite.h"
#include "entity/Sprite.h"

using namespace Game2D;

Player::Player(SDL_Texture* texture, int x, int y, int w, int h) : DamageableSprite(texture,x,y,w,h) {
    GE2D::EventHandler::registerEventCallback(std::vector<SDL_EventType> {SDL_KEYDOWN, SDL_KEYUP}, this);
}
Player::~Player(){
    GE2D::EventHandler::removeEventCallbacks(this);
}

void Player::update(GE2D::Scene& scene){
    if(move) {
        float dx = xVelocity * GE2D::GameEngine::deltaTime * 300; 
        _position->x += dx;
        _bounds.x = _position->x;
        // Check if colliding with tilemap
        for(GameObject* obj : scene.getTileMapObjects()){
            Sprite* sprite = dynamic_cast<Sprite*>(obj);
            if(sprite->getID() != getID() &&  sprite->getType() == SpriteType::GROUND){
                SDL_Rect collision;
                // If collision with wall revert move
                if(isColliding(*sprite, &collision)) {
                    _position->x -= dx;
                    _bounds.x = _position->x;
                    return;
                }
            }
        }
    }
    if(fireProjectile){
        GE2D::Vector2DInt* direction = new GE2D::Vector2DInt();
        direction->x = 0;
        direction->y = -1;
        // Add projectile to scene with upwards movement, damages enemy
        scene.addGameObject(new Projectile(Game::getTexture(SpriteType::PROJECTILE),
                (_position->x + (_bounds.w / 4)), _position->y, _bounds.w / 2, _bounds.h / 2,
                direction, std::vector<SpriteType>{SpriteType::ENEMY}));
        fireProjectile = false;
    }
}

void Player::handleEvent(SDL_Event& event){
    changeVelocity(event);
    shoot(event);
}

// Removes healthpoints from the player class
void Player::takeDamage(GE2D::Scene& scene, float damage) {
    if((healthPoints - damage) <= 0){
        healthPoints = 0;
        scene.removeGameObject(*this);
    } else {
        healthPoints -= damage;
    }
}

// Changes velocity depending on user keyboard input
void Player::changeVelocity(SDL_Event& event){
    float change = 1;
    if(GE2D::InputSystem::getInstance().getKeyDown(SDLK_d) 
            || GE2D::InputSystem::getInstance().getKeyUp(SDLK_a)){
        xVelocity+=change;
    }
    else if(GE2D::InputSystem::getInstance().getKeyDown(SDLK_a) 
            || GE2D::InputSystem::getInstance().getKeyUp(SDLK_d)){
        xVelocity-=change;
    }
    move = xVelocity > 0 || xVelocity < 0 ? 1 : 0;
}

void Player::shoot(SDL_Event& event){
    if(GE2D::InputSystem::getInstance().getKeyDown(SDLK_SPACE)){
        fireProjectile = true;
    }
}