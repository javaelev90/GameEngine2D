#include <iostream>
#include <chrono>

#include "engine/GameEngine.h"
#include "engine/EngineException.h"
#include "engine/EventHandler.h"

using namespace GE2D;

float GameEngine::deltaTime = 0.0f;

GameEngine::GameEngine(){
    init();
}

GameEngine::GameEngine(int fps){
    setFps(fps);
    init();
}

GameEngine::~GameEngine(){
    cleanUp();
}

void GameEngine::setFps(int fps){
    if(fps < 0){
        throw EngineException("FPS value is too low, has to be > 0.");
    } 
    _fps = fps;
}
void GameEngine::init() {
    if(!_initialized) {
        if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) 
        {
            throw EngineException("Error SDL2 Initialization. Error: " + std::string(SDL_GetError()));
        }
        if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP) <= 0) 
        {
            throw EngineException("Error SDL2 Initialization. Error: " + std::string(IMG_GetError()));
        }
        _initialized = true;
    }
}

// ---- Game loop algorithm ----
//
// record start time
// timeelapsed = getTime - start time
// while timeelapsed < frametime / 2
//      startlogic = getTime
//      while events
//          handle event
//      update logic
//      deltatime = getTime - startlogic
//      timeelapsed += deltatime
// render
// if timeelapsed < frametime
//      sleep until timeelapsed >= frametime

void GameEngine::run(){
    try {
        if(!_initialized) {
            init();
        }
        auto frameTimeInMs = std::chrono::milliseconds(1000 / _fps);
        auto halfFrameTimeInMs = frameTimeInMs / 2;
        auto minLogicFrameChangeMs = std::chrono::milliseconds(_fps / 10);
        _running = true;
        while (_running) {
            currentTime = getTimeInMiliseconds();
            elapsedTime = getTimeInMiliseconds() - currentTime;
            // The logic loop will use at least half of the frame time
            while((elapsedTime + minLogicFrameChangeMs) <= halfFrameTimeInMs){
                startLogic = getTimeInMiliseconds();

                SDL_Event e;
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        _running = false;
                        return;
                    }
                    Mouse::getInstance().updateMouseState(e.motion, e.button, e.wheel);
                    Keyboard::getInstance().updateKeyboardState(e.key);

                    EventHandler::handleEvent(e);
                }
                _scene->update();
                timeChange = getTimeInMiliseconds() - startLogic;
                elapsedTime += timeChange + minLogicFrameChangeMs;
                deltaTime = (timeChange + minLogicFrameChangeMs).count() / 1000.0f;
            }
            // Let rendering have the other half of the frame time
            renderObjects();
            if(elapsedTime < frameTimeInMs) {
                SDL_Delay((frameTimeInMs - elapsedTime).count());
            }
        }
    } catch(EngineException& exception) {
        std::cout << exception.getMessage() << std::endl;
    }
}

void GameEngine::stop(){
    _running = false;
}

void GameEngine::cleanUp(){
    delete _scene;
    delete _renderer;
    IMG_Quit();
    SDL_Quit();
}

void GameEngine::renderObjects(){
    _renderer->clear();
    // Render tilemap objects
    for(size_t i = 0; i < _scene->getTileMapObjects().size(); i++){
        _scene->getTileMapObjects().at(i)->draw(_renderer);
    }
    // Render game objects
    for(size_t i = 0; i < _scene->getGameObjects().size(); i++){
        if(dynamic_cast<Sprite*>(_scene->getGameObjects().at(i))){
            ((Sprite*)_scene->getGameObjects().at(i))->draw(_renderer);
        }
    }
    _renderer->display();
}