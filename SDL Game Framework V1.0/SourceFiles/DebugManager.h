/*
 * DebugManager.h
 * Purpose: To print out value/information of game on console window
 * and render collision box, text and line for developer in debugging process.
 * 
 * Bugs: none known
 * 
 * Last updated: 03/18/17
 */

#ifndef _DEBUG_MANAGER_H
#define _DEBUG_MANAGER_H

#include <Windows.h>
#include <memory>
#include <iostream>
#include <string>

class DebugManager
{
public:
	DebugManager();
	~DebugManager();

	void Init();

	//	Cursor within console window - recommend to disable to reduce disturbance
	static void ShowConsoleCursor(bool showFlag);

	////	Set cursor without @para-strings
	//static void SetCursorPosition(COORD coord);

	//	Set cursor position with specified cout string
	static void SetCursorPosition(COORD coord = { SHORT(0), SHORT(s_stringRow) });
	static void DebugLog(std::string);

	//	Information prompt onto the sized console window
	//	@para - wanted screen width and height
	static void SetConsoleWindowSize(int width, int height);

	//	A console handle is used by window console to handle buffer input and output
	static HANDLE hConsole;

	//	String counter to allocate y position for string output
	static int s_stringRow;
};

extern std::auto_ptr<DebugManager>	g_DebugManager;	//	Global FrameTimer object

#endif // !_DEBUG_MANAGER_H


