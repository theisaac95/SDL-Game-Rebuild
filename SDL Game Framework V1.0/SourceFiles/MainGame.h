#ifndef _MAIN_GAME_H
#define _MAIN_GAME_H

#include <memory>

#include "GameWindow.h"
//#include "FrameTimer.h"
#include "DebugManager.h"

class MainGame
{
public:
	MainGame(std::string title	= "Framework Tester",
			int posX			= SDL_WINDOWPOS_CENTERED,
			int posY			= SDL_WINDOWPOS_CENTERED,
			int screenWidth		= SCREEN_WIDTH,
			int screenHeight	= SCREEN_HEIGHT,
			bool isFullScreen	= false,
			int fps				= 60);
	~MainGame();

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

	// timer
	int _fps;
	int _frameDelay;

	GameWindow		* g_GameWindow;
	DebugManager	* g_DebugManager;
};

#endif // !_MAIN_GAME_H
