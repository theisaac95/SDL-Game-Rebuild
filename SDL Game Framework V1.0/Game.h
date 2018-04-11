#ifndef _GAME_H
#define _GAME_H	

#include "SDL.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdint.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game
{
public:
	Game();
	Game(std::string title,
		int posX,
		int posY,
		int screenWidth,
		int screenHeight,
		bool isFullScreen,
		int fps);
	~Game();

	void Init(std::string title = "Framework Tester",
		int posX = SDL_WINDOWPOS_CENTERED,
		int posY = SDL_WINDOWPOS_CENTERED,
		int screenWidth = SCREEN_WIDTH,
		int screenHeight = SCREEN_HEIGHT,
		bool isFullScreen = false,
		int fps = 60);
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

	// timer
	int _fps;
	int _frameDelay;
};

#endif // _GAME_H
