#include <windows.h>
#include "WinMain.h"
#include "Globals.h"
#include "Person.h"


#define WINDOW_CLASS_NAME		"EDITORCLASS"
#define WINDOW_NAME				"Map Editor"


HWND MainWnd;
HINSTANCE MainInst;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
	{
	WNDCLASSEX wndclass;
	MSG msg;

	MainInst = hInstance;

	memset(&wndclass, 0, sizeof(WNDCLASSEX));

	wndclass.cbSize			= sizeof(WNDCLASSEX);
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	= NULL;
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= WINDOW_CLASS_NAME;
	

	if (!RegisterClassEx(&wndclass))
		return 0;


#ifdef FULLSCREEN
	MainWnd = CreateWindowEx(WS_EX_TOPMOST, WINDOW_CLASS_NAME, WINDOW_NAME, WS_POPUP | WS_VISIBLE, 
							 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							 NULL, NULL, hInstance, NULL);
#else
	MainWnd = CreateWindowEx(0, WINDOW_CLASS_NAME, WINDOW_NAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
							 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							 NULL, NULL, hInstance, NULL);
#endif


	if (!MainWnd)
		return 0;


	if (!Game.Startup())
		{
		Game.Shutdown();
		return 0;
		}


	while(TRUE)
		{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
			}
		else
			Game.Main();
		}

	Game.Shutdown();

	return (msg.wParam);
	}




LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
	switch(msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		/*case WM_KEYDOWN:
			switch(wParam)
				{
				case VK_UP:
					//((CPerson *)Game.Object[0])->WalkUpTile();
					//Game.Person[0].DashUpTile();
					Game.Dropper.SlowPanUpTile();
					break;

				case VK_DOWN:
					//((CPerson *)Game.Object[0])->WalkDownTile();
					//Game.Person[0].DashDownTile();
					Game.Dropper.SlowPanDownTile();
					break;

				case VK_LEFT:
					//((CPerson *)Game.Object[0])->WalkLeftTile();
					//Game.Person[0].DashLeftTile();
					Game.Dropper.SlowPanLeftTile();
					break;

				case VK_RIGHT:
					//((CPerson *)Game.Object[0])->WalkRightTile();
					//Game.Person[0].DashRightTile();
					Game.Dropper.SlowPanRightTile();
					break;
				}
			return 0;*/
		}

	return DefWindowProc(hWnd, msg, wParam, lParam);
	}
