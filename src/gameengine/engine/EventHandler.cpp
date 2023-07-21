#include <iostream>
#include "engine/EventHandler.h"

using namespace GE2D;

std::map<Uint32, std::vector<GameObject*>> EventHandler::_eventTypeCallbacks;

EventHandler::EventHandler(){
}   
EventHandler::~EventHandler(){ 
}
void EventHandler::registerEventCallback(std::vector<SDL_EventType> types, GameObject* gameObject){
    for(SDL_EventType type : types){
        EventHandler::_eventTypeCallbacks[type].push_back(gameObject);
    }
}
void EventHandler::removeEventCallbacks(GameObject* gameObject) {
    for(auto entry : _eventTypeCallbacks){
        for(std::vector<GameObject*>::iterator it = _eventTypeCallbacks[entry.first].begin(); it != _eventTypeCallbacks[entry.first].end();){
            if((*it)->getID() == gameObject->getID()){
                it = _eventTypeCallbacks[entry.first].erase(it);
            } else {
                ++it;
            }
        } 
    }
}

bool EventHandler::handleEvent(SDL_Event& event){
    if(EventHandler::_eventTypeCallbacks[event.type].size() > 0) {
        for(auto gameObject : EventHandler::_eventTypeCallbacks[event.type]){
            gameObject->handleEvent(event);
        }
    }
    return true;
}