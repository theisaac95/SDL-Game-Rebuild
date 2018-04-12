#include "MainGame.h"

//std::auto_ptr<GameWindow> g_GameWindow(new GameWindow);
//std::auto_ptr<GameWindow> g_GameWindow(new GameWindow);
//std::auto_ptr<FrameTimer> g_FrameTimer(new FrameTimer);

MainGame::MainGame(std::string title,
					int posX,
					int posY,
					int screenWidth,
					int screenHeight,
					bool isFullScreen,
					int fps)
{

	////////////////////////////////////////
	// Initialize Engine
	////////////////////////////////////////

	g_GameWindow	= new GameWindow();
	g_DebugManager	= new DebugManager();
	g_DebugManager->ShowConsoleCursor(false);

	if (!g_GameWindow->Init(title, posX, posY, screenWidth, screenHeight, isFullScreen))
	{
		MessageBox(NULL, "Error Initialize Timer!",
			"SDL Subsystem Initialization Error", MB_OK | MB_ICONEXCLAMATION);
		SDL_Quit();
	}

	_fps = fps;
	_frameDelay = 1000 / fps;

	_gameIsRunning = true;
}

MainGame::~MainGame()
{
	delete g_GameWindow;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	SDL Event Handling
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void MainGame::HandleEvents()
{
	SDL_Event sdlEvent;
	SDL_PollEvent(&sdlEvent);

	switch (sdlEvent.type)
	{
	case SDL_QUIT:
		_gameIsRunning = false;
		system("CLS");
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
void MainGame::StartGame()
{
	GameLoop();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Game Loop
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void MainGame::GameLoop()
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

		g_DebugManager->s_stringRow = 0;
		system("CLS");
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Input - process input from users
	- getting rapid input without delay
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void MainGame::ProcessInput()
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
void MainGame::FixedUpdate()
{
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Game Update - game data update
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void MainGame::Update()
{
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Render - perform rendering of the game
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void MainGame::Render()
{
}