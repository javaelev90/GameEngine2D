#pragma once
#include <string>
#include <SDL2/SDL.h>

#include "GameObject.h"


namespace GE2D {
    
    class Renderer;

    class Sprite :
        public GameObject
    {
    public:
        virtual ~Sprite();
        void draw(Renderer* renderer);

        bool isColliding(Sprite& other, SDL_Rect* result);
        inline SDL_Texture* getTexture(){ return _texture; };
        inline SDL_Rect* getBounds() { return &_bounds; };
        inline Uint32 getType() {return _type; };
        inline void setType(Uint32 type) { _type = type; };
    protected:
        Sprite(SDL_Texture* texture);
        Sprite(SDL_Texture* texture, int x, int y, int w, int h);
        SDL_Texture* _texture;
        SDL_Rect _bounds;
        Uint32 _type;
    private:
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;
    };
}