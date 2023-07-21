#pragma once

#include "rendering/Renderer.h"
#include "input/InputSystem.h"
#include "engine/Scene.h"

namespace GE2D {

    class GameEngine {

        public:
            GameEngine();
            GameEngine(int fps);
            ~GameEngine();

            void run();
            void stop();

            void setFps(int fps);
            inline void setScene(Scene* scene){ _scene = scene; };
            inline void setRenderer(Renderer* renderer){ _renderer = renderer; };

            static float deltaTime;
        private:
            Scene* _scene = nullptr;
            Renderer* _renderer = nullptr;
            bool _running = false;
            int _fps = 60;
            bool _initialized = false;

            std::chrono::time_point<highResClock, ms> currentTime;
            std::chrono::time_point<highResClock, ms> startLogic;
            std::chrono::duration<int64_t, std::milli> elapsedTime;  
            std::chrono::duration<int64_t, std::milli> timeChange;

            std::chrono::milliseconds frameTimeInMs;
            std::chrono::milliseconds halfFrameTimeInMs;
            std::chrono::milliseconds minLogicFrameChangeMs;

            void init();
            void updateLogic();
            void handleEvents();
            void renderObjects();
            void cleanUp();

            GameEngine(const GameEngine& other) = delete;
            const GameEngine& operator=(const GameEngine& other) = delete;

    };
}