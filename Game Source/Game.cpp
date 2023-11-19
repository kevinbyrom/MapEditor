#include <windows.h>
#include <stdio.h>
#include "Game.h"
#include "DirectX.h"
#include "GFX.h"
#include "Input.h"
#include "Globals.h"
#include "Person.h"
#include "CurrTileGWnd.h"
#include "CurrBlockGWnd.h"




CGame::CGame()
	{
	InitObjectList();
	InitGWndList();
	}




int CGame::Startup()
	{
	BITMAP_FILE tilebmp, fontbmp, objectbmp;


	if (!InitDirectX())
		return FALSE;



	Load_Bitmap_File(&tilebmp, "LAND.BMP");
	Draw_Bitmap_To_Surface(&tilebmp, lpTile);
	lpPalette->SetEntries(0, 0, 256, tilebmp.palette);
	Unload_Bitmap_File(&tilebmp);


	Load_Bitmap_File(&fontbmp, "FONT.BMP");
	Draw_Bitmap_To_Surface(&fontbmp, lpFont);
	Unload_Bitmap_File(&fontbmp);


	Load_Bitmap_File(&objectbmp, "HERO1.BMP");
	Draw_Bitmap_To_Surface(&objectbmp, lpObject);
	Unload_Bitmap_File(&objectbmp);


	NumObjects = 1;


	Object[0] = new CPerson;

	MapView.Create(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 50, GWND_BACK_NONE, GWND_BORDER_THIN);

	Level.SetLevelSize(10, 10);

	SetEditMode(EDIT_MODE_DROPTILE);

	return TRUE;
	}






void CGame::Main()
	{
	FrameTimer.Start();


	InputLogic();


	// LOGIC //
	
	for (int i = 0; i < NumObjects; i++)
		Object[i]->DoLogic();

	Dropper.DoLogic();
	Camera.DoLogic();


	DisplayLogic();


	FrameTimer.Wait(60);
	}






void CGame::InputLogic()
	{
	PollKeyboard();


	// F2 ShowGrid Toggle //

	if (KeyPressed(DIK_F2))
		{
		Editor.ShowGrid = !Editor.ShowGrid;
		ClearKeyBuff();
		}


	// F3 ShowDropper Toggle //

	if (KeyPressed(DIK_F3))
		{
		Editor.ShowDropper = !Editor.ShowDropper;
		ClearKeyBuff();
		}


	// F4 Dropper Color //

	if (KeyPressed(DIK_F4))
		{
		Dropper.ChangeColor();
		ClearKeyBuff();
		}



	// F5 F6 F7 F8 Level Size //

	if (KeyPressed(DIK_F5))
		{
		if (Level.GetWidth() > 1)
			Level.SetLevelSize(Level.GetWidth() - 1, Level.GetHeight());

		ClearKeyBuff();
		}

	else if (KeyPressed(DIK_F6))
		{
		if (Level.GetWidth() < MAX_LEVEL_WIDTH)
			Level.SetLevelSize(Level.GetWidth() + 1, Level.GetHeight());

		ClearKeyBuff();
		}


	if (KeyPressed(DIK_F7))
		{
		if (Level.GetHeight() > 1)
			Level.SetLevelSize(Level.GetWidth(), Level.GetHeight() - 1);

		ClearKeyBuff();
		}

	else if (KeyPressed(DIK_F8))
		{
		if (Level.GetHeight() < MAX_LEVEL_HEIGHT)
			Level.SetLevelSize(Level.GetWidth(), Level.GetHeight() + 1);

		ClearKeyBuff();
		}



	switch(Editor.Mode)
		{
		case EDIT_MODE_DROPTILE:

			// ARROW KEYS //

			if (KeyPressed(DIK_LEFT))
				Game.Dropper.SlowPanLeftTile();

			else if (KeyPressed(DIK_RIGHT))
				Game.Dropper.SlowPanRightTile();

			else if (KeyPressed(DIK_UP))
				Game.Dropper.SlowPanUpTile();

			else if (KeyPressed(DIK_DOWN))
				Game.Dropper.SlowPanDownTile();


			// 7 or 9 CHANGE LVL1 TILE //

			if (KeyPressed(DIK_NUMPAD7))
				{
				if (Editor.Lvl1Tile == 0)
					Editor.Lvl1Tile = 255;
				else
					Editor.Lvl1Tile--;

				ClearKeyBuff();
				}

			else if (KeyPressed(DIK_NUMPAD9))
				{
				if (Editor.Lvl1Tile == 255)
					Editor.Lvl1Tile = 0;
				else
					Editor.Lvl1Tile++;

				ClearKeyBuff();
				}


			// 4 or 6 CHANGE LVL2 TILE //

			if (KeyPressed(DIK_NUMPAD4))
				{
				if (Editor.Lvl2Tile == 0)
					Editor.Lvl2Tile = 255;
				else
					Editor.Lvl2Tile--;

				ClearKeyBuff();
				}

			else if (KeyPressed(DIK_NUMPAD6))
				{
				if (Editor.Lvl2Tile == 255)
					Editor.Lvl2Tile = 0;
				else
					Editor.Lvl2Tile++;

				ClearKeyBuff();
				}


			// 1 or 3 CHANGE LVL3 TILE //

			if (KeyPressed(DIK_NUMPAD1))
				{
				if (Editor.Lvl3Tile == 0)
					Editor.Lvl3Tile = 255;
				else
					Editor.Lvl3Tile--;

				ClearKeyBuff();
				}

			else if (KeyPressed(DIK_NUMPAD3))
				{
				if (Editor.Lvl3Tile == 255)
					Editor.Lvl3Tile = 0;
				else
					Editor.Lvl3Tile++;

				ClearKeyBuff();
				}


			// 8,5,2 PLACE LVL TILE //

			if (KeyPressed(DIK_NUMPAD8))
				{
				Level.TileMap.SetLvl1Tile(TILE_POS_X(Dropper.X), TILE_POS_Y(Dropper.Y), Editor.Lvl1Tile);
				ClearKeyBuff();
				}

			if (KeyPressed(DIK_NUMPAD5))
				{
				Level.TileMap.SetLvl2Tile(TILE_POS_X(Dropper.X), TILE_POS_Y(Dropper.Y), Editor.Lvl2Tile);
				ClearKeyBuff();
				}

			if (KeyPressed(DIK_NUMPAD2))
				{
				Level.TileMap.SetLvl3Tile(TILE_POS_X(Dropper.X), TILE_POS_Y(Dropper.Y), Editor.Lvl3Tile);
				ClearKeyBuff();
				}



			// F1 CHANGE MODE //

			if (KeyPressed(DIK_F1))
				{
				SetEditMode(EDIT_MODE_DROPBLOCK);
				ClearKeyBuff();
				}
			break;



		case EDIT_MODE_DROPBLOCK:

			// ARROW KEYS //

			if (KeyPressed(DIK_LEFT))
				Game.Dropper.SlowPanLeftTile();

			else if (KeyPressed(DIK_RIGHT))
				Game.Dropper.SlowPanRightTile();

			else if (KeyPressed(DIK_UP))
				Game.Dropper.SlowPanUpTile();

			else if (KeyPressed(DIK_DOWN))
				Game.Dropper.SlowPanDownTile();



			// 7 or 9 CHANGE BLOCK //

			if (KeyPressed(DIK_NUMPAD7))
				{
				if (Editor.Block == 0)
					Editor.Block = 4;
				else
					Editor.Block--;

				ClearKeyBuff();
				}

			else if (KeyPressed(DIK_NUMPAD9))
				{
				if (Editor.Block == 4)
					Editor.Block = 0;
				else
					Editor.Block++;

				ClearKeyBuff();
				}



			// 8 Place Block //

			if (KeyPressed(DIK_NUMPAD8))
				{
				Level.BlockMap.SetBlock(TILE_POS_X(Dropper.X), TILE_POS_Y(Dropper.Y), Editor.Block);
				ClearKeyBuff();
				}



			// F1 CHANGE MODE //

			if (KeyPressed(DIK_F1))
				{
				SetEditMode(EDIT_MODE_MOVEOBJECT);
				ClearKeyBuff();
				}
			break;



		case EDIT_MODE_MOVEOBJECT:
			if (KeyPressed(DIK_LEFT))
				((CPerson *)Object[Editor.CurrObject])->WalkLeftTile();

			else if (KeyPressed(DIK_RIGHT))
				((CPerson *)Object[Editor.CurrObject])->WalkRightTile();

			else if (KeyPressed(DIK_UP))
				((CPerson *)Object[Editor.CurrObject])->WalkUpTile();

			else if (KeyPressed(DIK_DOWN))
				((CPerson *)Object[Editor.CurrObject])->WalkDownTile();


			if (KeyPressed(DIK_F1))
				{
				SetEditMode(EDIT_MODE_DROPTILE);
				ClearKeyBuff();
				}
			break;
		}
	}






void CGame::DisplayLogic()
	{
	Clear_Surface(lpWork);
	Clear_Surface(lpBack);


	MapView.Draw(lpWork);
	

	// Draw GWnds //

	for (int i = 0; i < NumGWnds; i++)
		GWnd[i]->Draw(lpWork);


	lpPrimary->Flip(NULL, DDFLIP_WAIT);
	}






void CGame::Shutdown()
	{
	RemoveAllObjects();
	RemoveAllGWnds();
	ShutDownDirectX();
	}





///////////////////////////
//						 //
// OBJECT LIST FUNCTIONS //
//						 //
///////////////////////////



void CGame::InitObjectList()
	{
	NumObjects = 0;

	for (int i = 0; i < MAX_OBJECTS; i++)
		{
		Object[i] = NULL;
		}
	}



void CGame::RemoveAllObjects()
	{
	for (int i = 0; i < NumObjects; i++)
		{
		delete Object[i];
		Object[i] = NULL;
		}

	NumObjects = 0;
	}




/////////////////////////
//					   //
// GWND LIST FUNCTIONS //
//					   //
/////////////////////////




void CGame::InitGWndList()
	{
	NumGWnds = 0;

	for (int i = 0; i < MAX_GWNDS; i++)
		{
		GWnd[i] = NULL;
		}
	}






void CGame::AddGWnd(CGWnd * pGWnd, int x, int y, int width, int height, int backstyle, int borderstyle)
	{
	if (NumGWnds >= MAX_GWNDS)
		{
		delete pGWnd;
		return;
		}


	pGWnd->Create(x, y, width, height, backstyle, borderstyle);
	GWnd[NumGWnds] = pGWnd;

	
	NumGWnds++;
	}






void CGame::RemoveAllGWnds()
	{
	for (int i = 0; i < NumGWnds; i++)
		{
		delete GWnd[i];
		GWnd[i] = NULL;
		}


	NumGWnds = 0;
	}






////////////////////
//				  //
// EDITOR OPTIONS //
//				  //
////////////////////



void CGame::SetEditMode(int mode)
	{
	RemoveAllGWnds();

	switch(mode)
		{
		case EDIT_MODE_DROPTILE:
			Camera.Attach(&Dropper);

			AddGWnd(new CCurrTileGWnd, SCREEN_WIDTH - 60, 0, 60, 100, GWND_BACK_GRADIENT, GWND_BORDER_THIN);
			break;



		case EDIT_MODE_DROPBLOCK:
			Camera.Attach(&Dropper);

			AddGWnd(new CCurrBlockGWnd, SCREEN_WIDTH - 100, 0, 100, 170, GWND_BACK_GRADIENT, GWND_BORDER_THIN);
			break;



		case EDIT_MODE_MOVEOBJECT:
			Camera.Attach(Object[Editor.CurrObject]);
			break;
		}


	Editor.Mode = mode;
	}