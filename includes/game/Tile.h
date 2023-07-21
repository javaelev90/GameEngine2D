#pragma once
#include "entity/Sprite.h"
#include "engine/Scene.h"

namespace Game2D {

    class Tile : public GE2D::Sprite {

        public:
            void update(GE2D::Scene& scene);
            void handleEvent(SDL_Event& event);
            Tile(SDL_Texture* texture, int x, int y, int w, int h);
    };

}