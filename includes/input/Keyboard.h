#pragma once
#include <map>
#include <SDL2/SDL.h>	

namespace GE2D {
    class Keyboard {
        public:
            static Keyboard& getInstance() {
                static Keyboard INSTANCE;
                return INSTANCE;
            };
            bool getKey(SDL_Keycode key);
            bool getKeyUp(SDL_Keycode key);
            bool getKeyDown(SDL_Keycode key);
            bool getKeyMod(SDL_Keymod keyMod);
            void updateKeyboardState(SDL_KeyboardEvent keyboardEvent);
        private:
            std::map<SDL_Keycode, bool> _pressedKeys;
            static SDL_KeyboardEvent _keyboardEvent;
            
            Keyboard(){};
            Keyboard(const Keyboard& other) = delete;
            const Keyboard& operator=(const Keyboard& other) = delete;
    };
}