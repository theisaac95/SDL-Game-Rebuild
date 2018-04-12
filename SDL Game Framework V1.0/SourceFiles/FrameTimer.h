#ifndef _FRAME_TIMER_H
#define _FRAME_TIMER_H


#include <Windows.h>
#include <memory>

class FrameTimer
{
public:
	FrameTimer();
	FrameTimer(double fps);
	~FrameTimer();

	BOOL	InitializeFPS(double fps);
	int		FramesToUpdate();

private:

	LARGE_INTEGER _timer_freq;
	LARGE_INTEGER _timer_now;
	LARGE_INTEGER _timer_previous;

	int		_requested_FPS;
	float	_intervalsPerFrame;
	float	_intervalSinceLastUpdate;

};

extern std::auto_ptr<FrameTimer>	g_FrameTimer;	//	Global FrameTimer object

#endif // !_FRAME_TIMER_H
