#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdio.h>
#include "engine/EngineException.h"

namespace GE2D {

    class Renderer {

    public:
        Renderer(const std::string windowTitle, int width, int height);
        ~Renderer();
        SDL_Texture* loadTexture(const std::string filePath);

        void render(SDL_Texture* texture, SDL_Rect& dst);
        void clear();
        void display();
    private:
        SDL_Renderer* _renderer;
        SDL_Window* _window;
        Renderer(const Renderer& other) = delete;
        const Renderer& operator=(const Renderer& other) = delete;
    };
}