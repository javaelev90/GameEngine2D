#pragma once
#include <map>
#include <vector>
#include <functional>
#include <iostream>
#include <SDL2/SDL.h>
#include <entity/GameObject.h>
namespace GE2D {
    class EventHandler {

        public:
            EventHandler();
            ~EventHandler();
            static void registerEventCallback(std::vector<SDL_EventType> types, GameObject* gameObject);
            static void removeEventCallbacks(GameObject* gameObject);
            static bool handleEvent(SDL_Event& event);
        private:
            static std::map<Uint32, std::vector<GameObject*>> _eventTypeCallbacks;
            
            EventHandler(const EventHandler& other) = delete;
            const EventHandler& operator=(const EventHandler& other) = delete;
    };
}