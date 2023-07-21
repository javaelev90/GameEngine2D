#pragma once
#include <string>
#include <SDL2/SDL.h>

#include "entity/Sprite.h"
#include "engine/Scene.h"

namespace Game2D {
    
    class Renderer;

    class DamageableSprite :
        public GE2D::Sprite
    {
    public:
        virtual ~DamageableSprite() {};
        virtual void takeDamage(GE2D::Scene& scene, float damage) = 0;
    protected:
        DamageableSprite(SDL_Texture* texture) : Sprite(texture){};
        DamageableSprite(SDL_Texture* texture, int x, int y, int w, int h) : Sprite(texture, x, y, w, h) {};
    private:
        DamageableSprite(const DamageableSprite& other) = delete;
        const DamageableSprite& operator=(const DamageableSprite& other) = delete;
    };
}