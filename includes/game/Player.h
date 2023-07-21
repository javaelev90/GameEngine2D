#pragma once

#include "engine/Scene.h"
#include "game/DamageAbleSprite.h"

namespace Game2D {

    class Player : public DamageableSprite {

        public:
            Player(SDL_Texture* texture, int x, int y, int w, int h);
            ~Player();
            void update(GE2D::Scene& scene);
            void handleEvent(SDL_Event& event);
            void takeDamage(GE2D::Scene& scene, float damage);
        private:
            float xVelocity = 0;
            float yVelocity = 0;
            bool fireProjectile = false;
            bool move = false;
            int healthPoints = 3;
            void changeVelocity(SDL_Event& event);
            void shoot(SDL_Event& event);
    };

}