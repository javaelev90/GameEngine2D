#pragma once
#include <vector>

#include "entity/Sprite.h"
#include "engine/Scene.h"
#include "game/Game.h"

namespace Game2D {

    // enum SpriteType;

    class Projectile : public GE2D::Sprite {

        public:
            Projectile(SDL_Texture* texture, int x, int y, int w, int h, GE2D::Vector2DInt* direction, std::vector<SpriteType> damagesSpriteTypes);
            ~Projectile();
            void update(GE2D::Scene& scene);
            void handleEvent(SDL_Event& event);
        private:
            GE2D::Vector2DInt* _direction;
            std::vector<SpriteType> damagesSpriteTypes;
    };

}