#include <iostream>
#include <string>
#include <vector>
#include <functional>
// Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
// Bifogas endast för test av SDL installation! 

#include <SDL2/SDL.h>			
#include <SDL2/SDL_image.h> 	
#include <SDL2/SDL_mixer.h> 	
#include <SDL2/SDL_ttf.h> 	

#include "input/InputSystem.h"
#include "engine/EventHandler.h"
#include "entity/Sprite.h"
#include "rendering/Renderer.h"
#include "engine/GameEngine.h"
#include "engine/Scene.h"
#include "game/Game.h"

using namespace GE2D;

int main(int argc, char* argv[]) {

    const int mapTileSizeX = 64;
    const int mapTileSizeY = 64;
	const int mapTileCountX = 13;
    const int mapTileCountY = 10;
	// Map of the game, each number represents a Sprite type
    std::vector<std::vector<int>> map = {
			{6,6,6,6,6,6,6,6,6,6,6,6,6},
			{6,0,0,2,0,2,0,0,0,0,0,0,6},
			{6,0,2,0,2,0,2,0,0,0,0,0,6},
			{6,0,0,0,0,0,0,0,0,0,0,0,6},
			{6,0,0,0,0,0,0,0,0,0,0,0,6},
			{6,0,0,0,0,0,0,0,0,0,0,0,6},
			{6,0,0,0,0,0,0,0,0,0,0,0,6},
			{6,0,0,0,0,0,0,0,0,0,0,0,6},
			{6,0,0,0,0,4,0,0,0,0,0,0,6},
			{1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

	// Paths to resources
	std::string imagePath = "./resources/images/";

	int fps = 60;
	GameEngine* gameEngine = new GameEngine(fps);
	int windowSizeX = mapTileCountX * mapTileSizeX;
	int windowSizeY = mapTileCountY * mapTileSizeY;
	Renderer* renderer = new Renderer("Zpace Invaderz", windowSizeX, windowSizeY);
   
    Game2D::Game* game = new Game2D::Game(imagePath);
	game->loadTextures(*renderer);
	Scene* scene = game->loadMap(map, mapTileSizeX, mapTileSizeY, *renderer);
	
	gameEngine->setRenderer(renderer);
	gameEngine->setScene(scene);
	gameEngine->run();

	delete game;
	delete gameEngine;

	return EXIT_SUCCESS;
}