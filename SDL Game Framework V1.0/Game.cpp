#include "Game.h"

Game::Game()
{
	Init();
}

Game::Game(std::string title,
	int posX,
	int posY,
	int screenWidth,
	int screenHeight,
	bool isFullScreen,
	int fps)
{
	Init(title, posX, posY, screenWidth, screenHeight, isFullScreen, fps);
}


Game::~Game()
{
	// destroy/Free up memory
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();

	// test - check if memory is free
	std::cout << "Game successfully quit" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Initialization
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::Init(std::string title,
	int posX,
	int posY,
	int screenWidth,
	int screenHeight,
	bool isFullScreen,
	int fps)
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

	_fps = 60;
	_frameDelay = 1000 / fps;

	_gameIsRunning = true;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SDL Event Handling
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::HandleEvents()
{
	SDL_Event sdlEvent;
	SDL_PollEvent(&sdlEvent);

	switch (sdlEvent.type)
	{
	case SDL_QUIT:
		_gameIsRunning = false;
		delete this;
		Sleep(1500);
		exit(1);
		break;
		//case SDL_KEYDOWN:
		//	std::cout << "KEY PRESSED" << std::endl;
		//	//Select surfaces based on key press
		//	switch (sdlEvent.key.keysym.sym)
		//	{
		//	case SDLK_UP:
		//		std::cout << "Key Up" << std::endl;
		//		break;

		//	case SDLK_DOWN:
		//		std::cout << "Key Down" << std::endl;
		//		break;

		//	case SDLK_LEFT:
		//		std::cout << "Key Left" << std::endl;
		//		break;

		//	case SDLK_RIGHT:
		//		std::cout << "Key Right" << std::endl;
		//		break;

		//	default:
		//		break;
		//	}
		//	break;
	default:
		break;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Start Game
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::StartGame()
{
	GameLoop();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Game Loop
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::GameLoop()
{
	// massive integer variable
	Uint32 frameStart;
	int frameTime;

	while (_gameIsRunning)
	{
		frameStart = SDL_GetTicks();

		HandleEvents();
		ProcessInput();
		FixedUpdate();
		Update();
		Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (_frameDelay > frameTime) {
			SDL_Delay(_frameDelay - frameTime);
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Input - process input from users
- getting rapid input without delay
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::ProcessInput()
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if (keystates[SDL_SCANCODE_UP])
	{
		std::cout << "KEY UP" << std::endl;
	}
	else if (keystates[SDL_SCANCODE_DOWN])
	{
		std::cout << "KEY DOWN" << std::endl;
	}
	else if (keystates[SDL_SCANCODE_LEFT])
	{
		std::cout << "KEY LEFT" << std::endl;
	}
	else if (keystates[SDL_SCANCODE_RIGHT])
	{
		std::cout << "KEY RIGHT" << std::endl;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Physics Update - update which mainly process the game physics
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::FixedUpdate()
{
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Game Update - game data update
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::Update()
{
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Render - perform rendering of the game
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Game::Render()
{
}



