#pragma once

#include <string>

namespace GE2D {

    class EngineException {
        public:
            EngineException(std::string errorMsg) : _errorMsg(errorMsg) {};
            ~EngineException(){};
            
            std::string getMessage() { return _errorMsg; };
        private:
            std::string _errorMsg;
    };
}