#include "DebugManager.h"

//	Output handle - to do the buffer output tasks (change font color, cursor position, etc)
HANDLE DebugManager::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int DebugManager::s_stringRow = 0;

DebugManager::DebugManager()
{
}

DebugManager::~DebugManager()
{
}

void DebugManager::Init()
{
	std::cout << "Debug Mode On" << std::endl;
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}


void DebugManager::ShowConsoleCursor(bool showFlag)
{
	//	uses within function
	CONSOLE_CURSOR_INFO cursorInfo;

	//	Retrieve info from global cursor
	GetConsoleCursorInfo(DebugManager::hConsole, &cursorInfo);

	//	Cursor visibility according to boolean(showFlag)
	cursorInfo.bVisible = showFlag;

	//	Global cursor info setting
	SetConsoleCursorInfo(DebugManager::hConsole, &cursorInfo);
}

void DebugManager::SetCursorPosition(COORD coord)
{
	SetConsoleCursorPosition(DebugManager::hConsole, coord);

	s_stringRow++;
}

//void DebugManager::SetCursorPosition(COORD coord, std::string string)
//{
//	SetConsoleCursorPosition(DebugManager::hConsole, coord);
//
//	std::cout << string << std::endl;
//}

void DebugManager::DebugLog(std::string string)
{
	SetCursorPosition({ SHORT(0), SHORT(s_stringRow) });

	std::cout << string << std::endl;

	s_stringRow++;
}

void DebugManager::SetConsoleWindowSize(int width, int height)
{
	//	Make a new string to store system command
	std::string sysCommandString;

	//	Store the system command
	sysCommandString += "MODE CON COLS=" + std::to_string(width) + " LINES=" + std::to_string(height);

	//	Convert system command string to const* char as the system() do nott accept string
	const char * sysCommandChar = sysCommandString.c_str();

	//	Call system command to change screen size
	system(sysCommandChar);
}
