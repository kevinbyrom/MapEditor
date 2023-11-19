#include <windows.h>
#include <math.h>
#include "MapViewGWnd.h"
#include "Gfx.h"
#include "Globals.h"
#include "DirectX.h"




void CMapViewGWnd::OnDraw(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	float NumTileX, NumTileY;
	int OffsetX, OffsetY;
	int x, y, i;
	int LowTileX, HighTileX;
	int LowTileY, HighTileY;

	RECT DestRect;
	RECT ViewRect;


	ViewRect.left		= Game.Camera.x - (m_Width / 2);
	ViewRect.top		= Game.Camera.y - (m_Height / 2);
	ViewRect.right		= Game.Camera.x + (m_Width / 2);
	ViewRect.bottom		= Game.Camera.y + (m_Height / 2);

	LowTileX	= TILE_POS_X(ViewRect.left);
	LowTileY	= TILE_POS_Y(ViewRect.left);
	HighTileX	= TILE_POS_X(ViewRect.right - 1);
	HighTileY	= TILE_POS_Y(ViewRect.bottom - 1);


	// Draw the level 1 tiles //

	for (y = LowTileY; y <= HighTileX; y++)
		for (x = LowTileX; x <= HighTileX; x++)
			{
			DestRect.left	= (x * TILE_WIDTH) - ViewRect.left - (TILE_WIDTH / 2);
			DestRect.top	= (y * TILE_HEIGHT) - ViewRect.top - (TILE_HEIGHT / 2);
			DestRect.right	= DestRect.left + TILE_WIDTH;
			DestRect.bottom	= DestRect.top + TILE_HEIGHT;

			Draw_Tile_To_Work(0, DestRect.left, DestRect.top, 0);
			Draw_Rect(lpWork, DestRect.left, DestRect.top, DestRect.right - 1, DestRect.bottom - 1, 1);
			}


	// Draw the person tiles //

	for (i = 0; i < Game.NumObjects; i++)
		{
		if (Game.Person[i].InRect(&ViewRect))
			{
			Game.Person[i].Draw(Game.Person[i].x - ViewRect.left, Game.Person[i].y - ViewRect.top);
			}
		}



	// Draw the dropper //

	Game.Dropper.Draw(Game.Dropper.x - ViewRect.left, Game.Dropper.y - ViewRect.top);
	}