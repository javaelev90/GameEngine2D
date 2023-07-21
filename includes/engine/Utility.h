#pragma once
#include <vector>
#include <chrono>

#include "entity/GameObject.h"

namespace GE2D {

    using highResClock = std::chrono::high_resolution_clock;
    using ms = std::chrono::milliseconds;

    template <class T>
    inline void deleteGameObjectFromVector(std::vector<T*>& vector, T* object){
        for(size_t i = 0; i < vector.size(); i++){
            if(dynamic_cast<GameObject*>(object)->getID() == vector.at(i)->getID()) {
                delete vector[i];
                vector[i] = nullptr;
                // This is okay since we break after erase
                vector.erase(vector.begin() + i);
                break;
            } 
        }
    };

    template <class T>
    void deleteGameObjectFromVectorUsingId(std::vector<T*>& vector, unsigned long id){
        for(size_t i = 0; i < vector.size(); i++){
            if(dynamic_cast<GameObject*>(vector.at(i))->getID() == id) {
                delete vector[i];
                vector[i] = nullptr;
                // This is okay since we break after erase
                vector.erase(vector.begin() + i);
                break;
            } 
        }
    };

    inline std::chrono::time_point<highResClock, ms> getTimeInMiliseconds(){
        return std::chrono::time_point_cast<ms>(highResClock::now());
    };
}
