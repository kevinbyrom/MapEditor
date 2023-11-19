#include <windows.h>
#include "CurrBlockGWnd.h"
#include "BlockMap.h"
#include "Gfx.h"
#include "Globals.h"




void CCurrBlockGWnd::OnDraw(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	int CenterX;


	CenterX = m_Width >> 1;


	Draw_Text_Center(lpSurface, "BLOCK", CenterX, 5);
	
	
	switch(Game.Editor.Block)
		{
		case BLOCK_ALLOW_NONE:
			Draw_Text_Center(lpSurface, "ALLOW NONE", CenterX, 15);
			break;


		case BLOCK_ALLOW_ALL:
			Draw_Text_Center(lpSurface, "ALLOW ALL", CenterX, 15);
			break;


		case BLOCK_ALLOW_LVL1:
			Draw_Text_Center(lpSurface, "ALLOW LVL1", CenterX, 15);
			break;


		case BLOCK_ALLOW_LVL2:
			Draw_Text_Center(lpSurface, "ALLOW LVL2", CenterX, 15);
			break;


		case BLOCK_ALLOW_LVL3:
			Draw_Text_Center(lpSurface, "ALLOW LVL3", CenterX, 15);
			break;
		}


	Draw_Text_Center(lpSurface, "NONE", CenterX, 35);
	Draw_Fill_Rect(lpSurface, CenterX - 8, 47, CenterX + 8, 57, 1);

	Draw_Text_Center(lpSurface, "ALL", CenterX, 60);
	Draw_Fill_Rect(lpSurface, CenterX - 8, 72, CenterX + 8, 82, 2);

	Draw_Text_Center(lpSurface, "LVL 1", CenterX, 85);
	Draw_Fill_Rect(lpSurface, CenterX - 8, 97, CenterX + 8, 107, 3);

	Draw_Text_Center(lpSurface, "LVL 2", CenterX, 110);
	Draw_Fill_Rect(lpSurface, CenterX - 8, 122, CenterX + 8, 132, 4);

	Draw_Text_Center(lpSurface, "LVL 3", CenterX, 135);
	Draw_Fill_Rect(lpSurface, CenterX - 8, 147, CenterX + 8, 157, 5);
	}