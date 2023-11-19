#include <windows.h>
#include "DirectX.h"
#include "Input.h"


#define KEYBOARD_DELAY 150


UCHAR Key[256];




void PollKeyboard()
	{
	lpKeyboard->GetDeviceState(sizeof(Key), (LPVOID)Key);
	}




int KeyPressed(int key)
	{
	if (Key[key] & 0x80)
		return TRUE;
	else 
		return FALSE;
	}






void ClearKeyBuff()
	{
	DWORD LastPollTick = GetTickCount();


	memset(Key, 0, sizeof(Key));

	while(GetTickCount() < LastPollTick + KEYBOARD_DELAY){}
	}