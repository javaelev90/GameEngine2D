#pragma once
#include <SDL2/SDL.h>	
#include <string>	

#include "Keyboard.h"
#include "Mouse.h"

namespace GE2D {
    class InputSystem
    {
    public:
        static InputSystem& getInstance() {
            static InputSystem INSTANCE;
            return INSTANCE;
        };
        int getHorizontalAxis();
        int getVerticalAxis();
        Vector2DInt getMousePosition();
        
        bool getMouseButtonPressed();
        bool getMouseButtonDown();
        bool getMouseButtonUp();

        bool getKey(SDL_Keycode keySym);
        bool getKeyUp(SDL_Keycode keySym);
        bool getKeyDown(SDL_Keycode keySym);
        bool getKeyMod(SDL_Keymod keyMod);
    private:
        InputSystem(){};
        InputSystem(const InputSystem& other) = delete;
        const InputSystem& operator=(const InputSystem& other) = delete;    

    };
}