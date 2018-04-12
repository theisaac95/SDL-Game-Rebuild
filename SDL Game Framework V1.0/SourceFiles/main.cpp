/*	Dependencies
*/

#include "SDL.h"
#include "MainGame.h"
//#include "main.h"

int main(int argc, char *argv[])
{
	MainGame* mainGame = nullptr;

	mainGame = new MainGame();

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

	return EXIT_SUCCESS;
}
