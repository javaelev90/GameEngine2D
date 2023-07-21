#include "input/Keyboard.h"
#include <iostream>

using namespace GE2D;

SDL_KeyboardEvent Keyboard::_keyboardEvent;

// Updates internal keyboard state and keeps track of which keys are pressed
void Keyboard::updateKeyboardState(SDL_KeyboardEvent keyboardEvent){
    Keyboard::_keyboardEvent = keyboardEvent;
    if(keyboardEvent.type == SDL_KEYDOWN){
        Keyboard::_pressedKeys[keyboardEvent.keysym.sym] = true;
    } else if(keyboardEvent.type == SDL_KEYUP) {
        Keyboard::_pressedKeys[keyboardEvent.keysym.sym] = false;
    }
}

bool Keyboard::getKey(SDL_Keycode keySym){
    return Keyboard::_pressedKeys[keySym];
};

bool Keyboard::getKeyDown(SDL_Keycode keySym){
    return (_keyboardEvent.type == SDL_KEYDOWN) && (_keyboardEvent.keysym.sym == keySym) && (_keyboardEvent.repeat == 0);
};

bool Keyboard::getKeyUp(SDL_Keycode keySym){
    return (_keyboardEvent.type == SDL_KEYUP) && (_keyboardEvent.keysym.sym == keySym);
};

// Check if keymod is used, the function disregards active num-lock and/or caps-lock
bool Keyboard::getKeyMod(SDL_Keymod keyMod) {
    return (((SDL_GetModState() & (KMOD_NUM & KMOD_CAPS & keyMod)) != 0) ||
            ((SDL_GetModState() & (KMOD_NUM & keyMod)) != 0)  ||
            ((SDL_GetModState() & (KMOD_CAPS & keyMod)) != 0) ||
            ((SDL_GetModState() &  keyMod) != 0));
}