/*	Dependencies
*/
#include "SDL.h";
#include "Game.h"
//#include "main.h"

int main(int argc, char *argv[])
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

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

	return EXIT_SUCCESS;
}
