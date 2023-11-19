#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "MapViewGWnd.h"
#include "Gfx.h"
#include "Globals.h"
#include "DirectX.h"




void CMapViewGWnd::OnDraw(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	int x, y, i;
	int LowTileX, HighTileX;
	int LowTileY, HighTileY;
	UCHAR Tile;
	RECT DestRect;
	RECT ViewRect;



	// Get the viewport dimensions //

	ViewRect.left		= Game.Camera.X - (m_Width / 2);
	ViewRect.top		= Game.Camera.Y - (m_Height / 2);
	ViewRect.right		= Game.Camera.X + (m_Width / 2);
	ViewRect.bottom		= Game.Camera.Y + (m_Height / 2);



	// Get the low and high tile positions //

	LowTileX	= TILE_POS_X(ViewRect.left);
	LowTileY	= TILE_POS_Y(ViewRect.top);
	HighTileX	= TILE_POS_X(ViewRect.right);
	HighTileY	= TILE_POS_Y(ViewRect.bottom);



	// Avoid drawing out of level boundaries //

	if (LowTileX < 0)							LowTileX = 0;
	if (LowTileX >= Game.Level.GetWidth())		LowTileX = Game.Level.GetWidth() - 1;

	if (HighTileX < 0)							HighTileX = 0;
	if (HighTileX >= Game.Level.GetWidth())		HighTileX = Game.Level.GetWidth() - 1;


	if (LowTileY < 0)							LowTileY = 0;
	if (LowTileY >= Game.Level.GetHeight())		LowTileY = Game.Level.GetHeight() - 1;

	if (HighTileY < 0)							HighTileY = 0;
	if (HighTileY >= Game.Level.GetHeight())	HighTileY = Game.Level.GetHeight() - 1;



	// Draw the level 1 tiles & block //

	for (y = LowTileY; y <= HighTileY; y++)
		for (x = LowTileX; x <= HighTileX; x++)
			{
			DestRect.left	= (x * TILE_WIDTH) - ViewRect.left;
			DestRect.top	= (y * TILE_HEIGHT) - ViewRect.top;
			DestRect.right	= DestRect.left + TILE_WIDTH;
			DestRect.bottom	= DestRect.top + TILE_HEIGHT;

			Tile = Game.Level.TileMap.GetLvl1Tile(x, y);

			if (Tile != INVALID_TILE)
				Draw_Tile_To_Work(Tile, DestRect.left, DestRect.top, 0);


			if (Game.Editor.Mode == EDIT_MODE_DROPBLOCK && Game.Editor.ShowGrid)
				Draw_Fill_Rect(lpWork, DestRect.left, DestRect.top, DestRect.right - 1, DestRect.bottom - 1, Game.Level.BlockMap.GetBlock(x, y) + 1);
			}



	// Draw the person tiles //

	for (i = 0; i < Game.NumObjects; i++)
		{
		if (Game.Object[i]->InRect(&ViewRect))
			Game.Object[i]->Draw(Game.Object[i]->X - ViewRect.left, Game.Object[i]->Y - ViewRect.top);
		}



	// Draw the level 2 tiles //

	for (y = LowTileY; y <= HighTileY; y++)
		for (x = LowTileX; x <= HighTileX; x++)
			{
			DestRect.left	= (x * TILE_WIDTH) - ViewRect.left;
			DestRect.top	= (y * TILE_HEIGHT) - ViewRect.top;
			DestRect.right	= DestRect.left + TILE_WIDTH;
			DestRect.bottom	= DestRect.top + TILE_HEIGHT;

			Tile = Game.Level.TileMap.GetLvl2Tile(x, y);

			if (Tile != INVALID_TILE)
				Draw_Tile_To_Work(Tile, DestRect.left, DestRect.top, 0);
			}



	// Draw the level 3 tiles, & Grid //

	for (y = LowTileY; y <= HighTileY; y++)
		for (x = LowTileX; x <= HighTileX; x++)
			{
			DestRect.left	= (x * TILE_WIDTH) - ViewRect.left;
			DestRect.top	= (y * TILE_HEIGHT) - ViewRect.top;
			DestRect.right	= DestRect.left + TILE_WIDTH;
			DestRect.bottom	= DestRect.top + TILE_HEIGHT;

			Tile = Game.Level.TileMap.GetLvl3Tile(x, y);

			if (Tile != INVALID_TILE)
				Draw_Tile_To_Work(Tile, DestRect.left, DestRect.top, 0);


			if (Game.Editor.ShowGrid)
				Draw_Rect(lpWork, DestRect.left, DestRect.top, DestRect.right - 1, DestRect.bottom - 1, 1);
			}



	// Draw the dropper //

	if (Game.Editor.ShowDropper)
		Game.Dropper.Draw(Game.Dropper.X - ViewRect.left, Game.Dropper.Y - ViewRect.top);
	}