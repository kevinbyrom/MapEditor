#ifndef __Game_H
#define __Game_H


#include "GObject.h"

#include "FrameTimer.h"
#include "GWnd.h"
#include "MapViewGWnd.h"

#include "Dropper.h"
#include "Camera.h"
#include "Level.h"



#define MAX_OBJECTS			30
#define MAX_GWNDS			20



#define EDIT_MODE_DROPTILE		0
#define EDIT_MODE_DROPBLOCK		1
#define EDIT_MODE_DROPOBJECT	2
#define EDIT_MODE_MOVEOBJECT	3



struct EDITOR
	{
	EDITOR()		{ Mode = EDIT_MODE_DROPTILE; Lvl1Tile = 0; Lvl2Tile = 0; Lvl3Tile = 0; 
					  Block = 0; CurrObject = 0; ShowDropper = 1; ShowGrid = 1;}
	
	int Mode;

	int ShowDropper,
		ShowGrid;

	UCHAR Lvl1Tile,
		  Lvl2Tile,
		  Lvl3Tile;

	UCHAR Block;

	int CurrObject;
	};




class CGame
	{
	public:

		CGame();

		int Startup();
		void Main();
		void Shutdown();

		EDITOR Editor;


		CFrameTimer FrameTimer;
		CMapViewGWnd MapView;
	
		

		CDropper Dropper;
		CCamera Camera;
		CLevel Level;			// Collection of TileMap, BlockMap, etc....


		CGObject * Object[MAX_OBJECTS];
		CGWnd * GWnd[MAX_GWNDS];

		int NumObjects;
		int NumGWnds;


	protected:

		void InputLogic();
		void DisplayLogic();

		void InitObjectList();
		void RemoveAllObjects();

		void InitGWndList();
		void AddGWnd(CGWnd * pGWnd, int x, int y, int width, int height, int backstyle, int borderstyle);
		void RemoveAllGWnds();

		void SetEditMode(int mode);
	};


#endif