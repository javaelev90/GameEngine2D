#include "input/InputSystem.h"

using namespace GE2D;

int InputSystem::getHorizontalAxis(){
    return Mouse::getInstance().getHorizontalAxis();
}
int InputSystem::getVerticalAxis(){
    return Mouse::getInstance().getVerticalAxis();
}

Vector2DInt InputSystem::getMousePosition(){
    return Mouse::getInstance().getMousePosition();
}

bool InputSystem::getMouseButtonPressed(){
    return Mouse::getInstance().getMouseButtonPressed();
}
bool InputSystem::getMouseButtonDown(){
    return Mouse::getInstance().getMouseButtonDown();
}
bool InputSystem::getMouseButtonUp(){
    return Mouse::getInstance().getMouseButtonUp();
}

bool InputSystem::getKey(SDL_Keycode keySym){
    return Keyboard::getInstance().getKey(keySym);
}
bool InputSystem::getKeyUp(SDL_Keycode keySym){
    return Keyboard::getInstance().getKeyUp(keySym);
}
bool InputSystem::getKeyDown(SDL_Keycode keySym){
    return Keyboard::getInstance().getKeyDown(keySym);
}

bool InputSystem::getKeyMod(SDL_Keymod keyMod){
    return Keyboard::getInstance().getKeyMod(keyMod);
}

