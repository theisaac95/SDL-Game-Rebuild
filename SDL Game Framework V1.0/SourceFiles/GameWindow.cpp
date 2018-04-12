#include "GameWindow.h"

GameWindow::GameWindow()
{
	//Init();
}

GameWindow::GameWindow(std::string title,
						int posX,
						int posY,
						int screenWidth,
						int screenHeight,
						bool isFullScreen)
{
	//Init(title, posX, posY, screenWidth, screenHeight, isFullScreen);
}


GameWindow::~GameWindow()
{
	// destroy/Free up memory
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();

	// free memory
	std::cout << "GameWindow successfully cleared" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Initialization
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool GameWindow::Init(std::string title,
	int posX,
	int posY,
	int screenWidth,
	int screenHeight,
	bool isFullScreen)
{
	// initialize SDL subsystem
	if (SDL_Init(SDL_INIT_EVERYTHING) == 1)
	{
		MessageBox(NULL, "Error Creating SDL Subsystem!",
			"SDL Subsystem Initialization Error", MB_OK | MB_ICONEXCLAMATION);
		SDL_Quit();
	}

	// initialize SDL window
	_window = SDL_CreateWindow(
		title.c_str(),
		posX,
		posY,
		screenWidth,
		screenHeight,
		isFullScreen == false ? 0 : SDL_WINDOW_FULLSCREEN
	);

	if (_window == false)
	{
		MessageBox(NULL, "Error Creating Window!",
			"Window Initialization Error", MB_OK | MB_ICONEXCLAMATION);
		SDL_Quit();
	}

	// initialize SDL renderer
	_renderer = SDL_CreateRenderer(_window, -1, 0);

	if (_window == false)
	{
		SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
		MessageBox(NULL, "Error Creating Window!",
			"Window Initialization Error", MB_OK | MB_ICONEXCLAMATION);
		SDL_Quit();
	}

	return TRUE;
}



