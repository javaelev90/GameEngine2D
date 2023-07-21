#include "input/Mouse.h" 

using namespace GE2D;

SDL_MouseMotionEvent Mouse::_motion;
SDL_MouseButtonEvent Mouse::_button;
SDL_MouseWheelEvent Mouse::_wheel; 

Vector2DInt Mouse::getMousePosition(){
    SDL_GetMouseState(&_position.x, &_position.y);
    return _position;
};

int Mouse::getHorizontalAxis(){
    return (int) Mouse::_motion.xrel;
};

int Mouse::getVerticalAxis(){
    return (int) Mouse::_motion.yrel;
};

bool Mouse::getMouseButtonPressed(){
    return SDL_GetMouseState(NULL, NULL) == SDL_PRESSED;
};

bool Mouse::getMouseButtonDown(){
    return SDL_MOUSEBUTTONDOWN == Mouse::_button.type;
};

bool Mouse::getMouseButtonUp(){
    return SDL_MOUSEBUTTONUP == Mouse::_button.type;
};

void Mouse::updateMouseState(SDL_MouseMotionEvent motion, SDL_MouseButtonEvent button, SDL_MouseWheelEvent wheel){
    Mouse::_motion = motion;
    Mouse::_button = button;
    Mouse::_wheel = wheel;
};