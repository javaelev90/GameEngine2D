#pragma once
#include "engine/Scene.h"
#include "DamageAbleSprite.h"

namespace Game2D {

    class Enemy : public DamageableSprite {

        public:
            Enemy(SDL_Texture* texture, int x, int y, int w, int h);

            void update(GE2D::Scene& scene);
            void handleEvent(SDL_Event& event);

            void takeDamage(GE2D::Scene& scene, float damage);
        protected:
            ~Enemy();
        private:
            static float xDirection;
            static float yLevel;
            
            GE2D::Vector2DInt* startPosition;
            void changeDirection();
            void changePosition(float dx, float dy);
    };

}