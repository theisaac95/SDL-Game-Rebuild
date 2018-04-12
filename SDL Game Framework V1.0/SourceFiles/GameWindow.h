#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H	

#include "SDL.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdint.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class GameWindow
{
public:
	GameWindow();
	GameWindow(std::string title,
				int posX,
				int posY,
				int screenWidth,
				int screenHeight,
				bool isFullScreen);
	~GameWindow();

	bool Init(std::string title		= "Framework Tester",
				int posX			= SDL_WINDOWPOS_CENTERED,
				int posY			= SDL_WINDOWPOS_CENTERED,
				int screenWidth		= SCREEN_WIDTH,
				int screenHeight	= SCREEN_HEIGHT,
				bool isFullScreen	= false);

private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif // _GAME_WINDOW_H
