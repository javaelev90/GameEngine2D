#pragma once
#include <SDL2/SDL.h>	
#include "entity/GameObject.h"

namespace GE2D {
    class Mouse {

        public:
            static Mouse& getInstance() {
                static Mouse INSTANCE;
                return INSTANCE;
            };
            Vector2DInt getMousePosition();

            int getHorizontalAxis();
            int getVerticalAxis();

            bool getMouseButtonPressed();
            bool getMouseButtonDown();
            bool getMouseButtonUp();

            void updateMouseState(SDL_MouseMotionEvent motion, SDL_MouseButtonEvent button, SDL_MouseWheelEvent wheel);
        private:
            static SDL_MouseMotionEvent _motion;
            static SDL_MouseButtonEvent _button;
            static SDL_MouseWheelEvent _wheel; 
            Vector2DInt _position;

            Mouse(){};
            Mouse(const Mouse& other) = delete;
            const Mouse& operator=(const Mouse& other) = delete;
    };
}