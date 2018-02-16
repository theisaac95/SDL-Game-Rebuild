/*	Dependencies
*/
#include "SDL.h";
#include "Game.h"
#include "main.h"

int main(int argc, char *argv[]) 
{
	Game* mainGame = nullptr;

	mainGame = new Game();

	try
	{
		mainGame->StartGame();
	}
	catch (const std::exception& errorMsg)
	{
		std::cerr << "Error: " << errorMsg.what() << std::endl;
		MessageBoxA(NULL, "Error", "Game failed to initialize.", MB_OK | MB_ICONEXCLAMATION);

		return EXIT_FAILURE;
	}

	return 0;
}
