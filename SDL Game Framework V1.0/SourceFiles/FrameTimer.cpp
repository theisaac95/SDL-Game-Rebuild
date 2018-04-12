#include "FrameTimer.h"


FrameTimer::FrameTimer() :FrameTimer(30.0)
{
}

FrameTimer::FrameTimer(double fps)
{
	InitializeFPS(fps);
}

FrameTimer::~FrameTimer()
{
}

//	Game starting Frame per second initialization
BOOL FrameTimer::InitializeFPS(double fps)
{
	QueryPerformanceFrequency(&_timer_freq);
	QueryPerformanceCounter(&_timer_now);
	QueryPerformanceCounter(&_timer_previous);

	//	initiate fps time info
	_requested_FPS = fps;

	//	The number of intervals in the given timer, per frame at the requested rate.
	_intervalsPerFrame = ((float)_timer_freq.QuadPart / _requested_FPS);

	return TRUE;
}

//	Always return stable frames
int FrameTimer::FramesToUpdate()
{
	int framesToUpdate = 0;
	QueryPerformanceCounter(&_timer_now);

	//	getting the delta time
	_intervalSinceLastUpdate = (float)_timer_now.QuadPart - (float)_timer_previous.QuadPart;

	framesToUpdate = (int)(_intervalSinceLastUpdate / _intervalsPerFrame);

	//	if frame not update, keep the old previous timer count
	if (framesToUpdate != 0)
	{
		QueryPerformanceCounter(&_timer_previous);
	}

	return framesToUpdate;

}
