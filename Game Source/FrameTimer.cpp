#include <windows.h>
#include "FrameTimer.h"



CFrameTimer::CFrameTimer()
	{
	last_count = GetTickCount();
	}





void CFrameTimer::Start()
	{
	last_count = GetTickCount();
	}




void CFrameTimer::Wait(int frames_per_sec)
	{
	while(GetTickCount() - last_count < 30);
	}