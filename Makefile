SRC_DIR = src
SRC_DIR2 = src/**/**
SRC_DIR3 = src/**
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES2 = $(wildcard $(SRC_DIR2)/*.cpp)
SRC_FILES3 = $(wildcard $(SRC_DIR3)/*.cpp)
OBJ_NAME = play
COMPILER_FLAGS = -std=c++14 -Wall -O0 -g

# The user has to specify which environment to build for
# by providing a make argument like: env=linux|windows
# f.e. make env=linux

ifeq ($(env), linux)
    # Linux make values
    INCLUDE_PATHS = -Iincludes -I/usr/include/SDL2
    LIBRARY_PATHS = -Llib -L/usr/lib/x86_64-linux-gnu
    LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

    linux:
		$(CC) $(SRC_FILES) $(SRC_FILES2) $(SRC_FILES3) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(OBJ_NAME) 
else ifeq ($(env), windows)
    # Windows make values
    INCLUDE_PATHS = -Iincludes -IC:/msys64/mingw64/include
    LIBRARY_PATHS = -Llib -LC:/msys64/mingw64/lib
    LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
    
    windows:
		$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(SRC_FILES2) $(SRC_FILES3) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(OBJ_NAME)
else
    # Error message
    MSG = You need to provide an environment value: make env=windows|linux
    no-env:
		$(info $(MSG))
endif