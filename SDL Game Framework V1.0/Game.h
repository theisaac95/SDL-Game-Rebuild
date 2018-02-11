#ifndef _GAME_H
#define _GAME_H	

#include "SDL.h"
#include <iostream>
#include <string>
#include <Windows.h>

class Game
{
public:
	Game();
	Game(std::string title, int posX, int posY, int screenWidth, int screenHeight, bool isFullScreen);
	~Game();

	void Init(std::string title = "Unnamed Game", int posX = SDL_WINDOWPOS_CENTERED, int posY = SDL_WINDOWPOS_CENTERED, int screenWidth = 640, int screenHeight = 480, bool isFullScreen = false);
	void HandleEvents();
	void StartGame();
	void GameLoop();

	/*	Game Loop Flow
	*	- Receive/Process Input
	*	- Process Physics
	*	- Process Update
	*	- Render
	*/
	void ProcessInput();
	void FixedUpdate();
	void Update();
	void Render();

private:
	bool _gameIsRunning;
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif // _GAME_H
