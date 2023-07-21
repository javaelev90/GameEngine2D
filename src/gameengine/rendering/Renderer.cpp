#include <iostream>
#include <string>

#include "rendering/Renderer.h"
#include "engine/EngineException.h"
#include "entity/Sprite.h"

using namespace GE2D;

Renderer::Renderer(const std::string windowTitle, int width, int height)
        :_renderer(nullptr) {
    
    _window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);        
    if(_window == NULL) {
        throw EngineException("Could not initiate the game window. Error: " + std::string(SDL_GetError()));
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(_renderer == NULL) {
        throw EngineException("Could not initiate the renderer. Error: " + std::string(SDL_GetError()));
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

SDL_Texture* Renderer::loadTexture(const std::string filePath) {
    SDL_Texture* texture = IMG_LoadTexture(_renderer, filePath.c_str());
    if(texture == NULL) {
        throw EngineException("Could not load the texture. Error: " + std::string(SDL_GetError()));
    }
    return texture;
}

void Renderer::render(SDL_Texture* texture, SDL_Rect& dst){   
    SDL_RenderCopy(_renderer, texture, NULL, &dst);
}

void Renderer::clear(){
    SDL_RenderClear(_renderer);
}

void Renderer::display(){
    SDL_RenderPresent(_renderer);
}
