#ifndef __FrameTimer_H
#define __FrameTimer_H


class CFrameTimer
	{
	public:

		CFrameTimer();

		void Start();
		void Wait(int frames_per_sec);


	protected:

		DWORD last_count;
	};



#endif