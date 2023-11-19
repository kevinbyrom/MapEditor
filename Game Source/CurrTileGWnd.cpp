#include <windows.h>
#include "CurrTileGWnd.h"
#include "Gfx.h"
#include "Globals.h"




void CCurrTileGWnd::OnDraw(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	int CenterX;


	CenterX = m_Width >> 1;


	Draw_Text_Center(lpSurface, "LVL 1", CenterX, 5);
	Draw_Tile_To_Work(Game.Editor.Lvl1Tile, CenterX - (TILE_WIDTH / 2), 15, 0);


	Draw_Text_Center(lpSurface, "LVL 2", CenterX, 35);
	Draw_Tile_To_Work(Game.Editor.Lvl2Tile, CenterX - (TILE_WIDTH / 2), 45, 0);


	Draw_Text_Center(lpSurface, "LVL 3", CenterX, 65);
	Draw_Tile_To_Work(Game.Editor.Lvl3Tile, CenterX - (TILE_WIDTH / 2), 75, 0);
	}