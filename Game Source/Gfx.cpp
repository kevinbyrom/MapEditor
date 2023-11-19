#include <windows.h>
#include <stdio.h>
#include "DirectX.h"
#include "GFX.h"



void Clear_Surface(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	DDBLTFX ddbltfx;


	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);


	ddbltfx.dwFillColor = 0;


	lpSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
	}






void Clear_Surface_To_Color(LPDIRECTDRAWSURFACE4 lpSurface, int color)
	{
	DDBLTFX ddbltfx;


	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);


	ddbltfx.dwFillColor = color;


	lpSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
	}






void Blit_Work_To_Back(int x, int y, int sx, int sy, int swidth, int sheight, int trans)
	{
	RECT Rect;

	Rect.left		= sx;
	Rect.top		= sy;
	Rect.right		= sx + swidth;
	Rect.bottom		= sy + sheight;

	if (trans)
		lpBack->BltFast(x, y, lpWork, &Rect, DDBLTFAST_SRCCOLORKEY);
	else
		lpBack->BltFast(x, y, lpWork, &Rect, 0);
	}






void Draw_HLine(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int x1, int y, int color)
	{
	DDBLTFX ddbltfx;
	RECT rect;


	if (x0 < 0 && x1 < 0 ||
		x0 >= SCREEN_WIDTH && x1 >= SCREEN_WIDTH ||
		y < 0 || y >= SCREEN_HEIGHT)
		return;


	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);


	ddbltfx.dwFillColor = color;


	if (x0 < 0) x0 = 0;
	if (x0 >= SCREEN_WIDTH) x0 = SCREEN_WIDTH - 1;

	if (x1 < 0) x1 = 0;
	if (x1 >= SCREEN_WIDTH) x1 = SCREEN_WIDTH - 1;


	rect.left	= x0;
	rect.top	= y;
	rect.right	= x1 + 1;
	rect.bottom = y + 1;

	lpSurface->Blt(&rect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
	}






void Draw_VLine(LPDIRECTDRAWSURFACE4 lpSurface, int x, int y0, int y1, int color)
	{
	DDBLTFX ddbltfx;
	RECT rect;


	if (y0 < 0 && y1 < 0 ||
		y0 >= SCREEN_HEIGHT && y1 >= SCREEN_HEIGHT ||
		x < 0 || x >= SCREEN_WIDTH)
		return;


	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);


	ddbltfx.dwFillColor = color;


	if (y0 < 0) y0 = 0;
	if (y0 >= SCREEN_HEIGHT) y0 = SCREEN_HEIGHT - 1;

	if (y1 < 0) y1 = 0;
	if (y1 >= SCREEN_HEIGHT) y1 = SCREEN_HEIGHT - 1;


	rect.left	= x;
	rect.top	= y0;
	rect.right	= x + 1;
	rect.bottom = y1 + 1;

	lpSurface->Blt(&rect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
	}






void Draw_Rect(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int y0, int x1, int y1, int color)
	{
	Draw_HLine(lpSurface, x0, x1, y0,color);
	Draw_HLine(lpSurface, x0, x1, y1, color);
	Draw_VLine(lpSurface, x0, y0, y1, color);
	Draw_VLine(lpSurface, x1, y0, y1, color);
	}






void Draw_Rect_To_Work(int x0, int y0, int x1, int y1, int color)
	{
	Draw_Rect(lpWork, x0, y0, x1, y1, color);
	}






void Draw_Fill_Rect(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int y0, int x1, int y1, int color)
	{
	DDBLTFX ddbltfx;
	RECT fillrect;

	memset(&ddbltfx, 0, sizeof(ddbltfx));
	ddbltfx.dwSize = sizeof(ddbltfx);

	ddbltfx.dwFillColor = color;

	fillrect.left	= x0;
	fillrect.top	= y0;
	fillrect.right	= x1;
	fillrect.bottom	= y1;

	lpSurface->Blt(&fillrect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
	}






void Draw_Frame_Rect(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int y0, int x1, int y1, int color, int fillcolor)
	{
	Draw_Fill_Rect(lpSurface, x0, y0, x1, y1, fillcolor);
	Draw_Rect(lpSurface, x0, y0, x1, y1, color);
	}






void Draw_Gradient(LPDIRECTDRAWSURFACE4 lpSurface, int width, int height, int color1, int color2)
	{
	int steps, barheight;


	steps = color2 - color1 + 1;

	barheight = int(height / steps);


	for (int i = 0; i < steps; i++)
		Draw_Fill_Rect(lpSurface, 0, i * barheight, width, (i + 1) * barheight, color1 + i);
	}





void Draw_Text(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x, int y)
	{
	int len, xpos;
	int charx, chary;
	RECT Source;


	if (!strText)
		return;


	xpos = x;


	len = strlen(strText);


	for (int i = 0; i < len; i++)
		{
		charx = strText[i] - ((strText[i] / 16) * 16);
		chary = strText[i] / 16;

		Source.left		= (charx * FONT_WIDTH) + (charx + 1);
		Source.top		= (chary * FONT_HEIGHT) + (chary + 1);
		Source.right	= Source.left + FONT_WIDTH;
		Source.bottom	= Source.top + FONT_HEIGHT;

		lpSurface->BltFast(xpos, y, lpFont, &Source, DDBLTFAST_SRCCOLORKEY);

		xpos += FONT_WIDTH;
		}
	}






void Draw_Text_Center(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x, int y)
	{
	int textwidth;


	textwidth = strlen(strText) * FONT_WIDTH;

	Draw_Text(lpSurface, strText, x - (textwidth / 2), y);
	}






void Draw_Text_Box(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x1, int y1, int x2, int y2)
	{
	int len;
	int min, max, maxchars, maxheight;
	int ypos;
	char strWrite[257];
	int i, done = 0;


	len = strlen(strText);

	maxchars	= (x2 - x1) / FONT_WIDTH;
	maxheight	= y2 - y1;

	min		= 0;
	ypos	= 0;


	while(!done)
		{
		// Find the length of the next write // 

		max = 0;

		if (min + maxchars > len)
			{
			max = len - min + 1;
			done = 1;
			}
		else
			{
			for (i = maxchars; i > 0; i--)
				{
				if (strText[min + i] == ' ')
					{
					max = i;
					break;
					}
				}
			}


		// If we found a length, draw the text //

		if (max)
			{
			memcpy(strWrite, &strText[min], max);
			strWrite[max] = '\0';

			Draw_Text(lpSurface, strWrite, x1, y1 + ypos);

			ypos += FONT_HEIGHT + FONT_SPACING;

			min += max + 1;
			}
		else
			{	
			done = 1;
			}


		// If we have exceeded y boundary //

		if (ypos > maxheight - FONT_HEIGHT)
			done = 1;
		}
	}






void Draw_Text_Box_Center(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x1, int y1, int x2, int y2)
	{
	int len;
	int min, max, maxchars, maxheight;
	int ypos;
	char strWrite[257];
	int i, done = 0;
	int centerx;


	len = strlen(strText);

	maxchars	= (x2 - x1) / FONT_WIDTH;
	maxheight	= y2 - y1;

	min		= 0;
	ypos	= 0;

	centerx = (x1 + x2) / 2;


	while(!done)
		{
		// Find the length of the next write // 

		max = 0;

		if (min + maxchars > len)
			{
			max = len - min + 1;
			done = 1;
			}
		else
			{
			for (i = maxchars; i > 0; i--)
				{
				if (strText[min + i] == ' ')
					{
					max = i;
					break;
					}
				}
			}


		// If we found a length, draw the text //

		if (max)
			{
			memcpy(strWrite, &strText[min], max);
			strWrite[max] = '\0';

			Draw_Text_Center(lpSurface, strWrite, centerx, y1 + ypos);

			ypos += FONT_HEIGHT + FONT_SPACING;

			min += max + 1;
			}
		else
			{	
			done = 1;
			}


		// If we have exceeded y boundary //

		if (ypos > maxheight - FONT_HEIGHT)
			done = 1;
		}
	}






void Draw_Tile_To_Work(UCHAR Tile, int x, int y, int Trans)
	{
	int TileX, TileY;
	int OffsetX = 0, OffsetY = 0, OffsetW = 0, OffsetH = 0;
	int DrawClipped = FALSE;
	RECT Source;


	TileX = Tile - ((Tile / NUM_TILE_X) * NUM_TILE_X);
	TileY = Tile / NUM_TILE_Y; 


	if (x < 0)
		{
		OffsetX = -x;
		DrawClipped = TRUE;
		}

	if (y < 0)
		{
		OffsetY = -y;
		DrawClipped = TRUE;
		}

	if (x + TILE_WIDTH >= WORK_WIDTH)
		{
		OffsetW = (x + TILE_WIDTH) - WORK_WIDTH;
		DrawClipped = TRUE;
		}

	if (y + TILE_HEIGHT >= WORK_HEIGHT)	
		{
		OffsetH = (y + TILE_HEIGHT) - WORK_HEIGHT;
		DrawClipped = TRUE;
		}


	if (DrawClipped)
		{
		Source.left		= (TileX * TILE_WIDTH) + (TileX + 1) + OffsetX;
		Source.top		= (TileY * TILE_HEIGHT) + (TileY + 1) + OffsetY;
		Source.right	= Source.left + TILE_WIDTH - OffsetX - OffsetW;
		Source.bottom	= Source.top + TILE_HEIGHT - OffsetY - OffsetH;


		if (Trans)
			lpWork->BltFast(x + OffsetX, y + OffsetY, lpTile, &Source, DDBLTFAST_SRCCOLORKEY);
		else
			lpWork->BltFast(x + OffsetX, y + OffsetY, lpTile, &Source, 0);
		}
	else
		{
		Source.left		= (TileX * TILE_WIDTH) + (TileX + 1);
		Source.top		= (TileY * TILE_HEIGHT) + (TileY + 1);
		Source.right	= Source.left + TILE_WIDTH;
		Source.bottom	= Source.top + TILE_HEIGHT;


		if (Trans)
			lpWork->BltFast(x, y, lpTile, &Source, DDBLTFAST_SRCCOLORKEY);
		else
			lpWork->BltFast(x, y, lpTile, &Source, 0);
		}
	}







void Draw_Object_To_Work(int ImageID, int x, int y, int sx, int sy, int width, int height)
	{
	int OffsetX = 0, OffsetY = 0, OffsetW = 0, OffsetH = 0;
	int DrawClipped = FALSE;
	RECT Source;
	

	if (x < 0) 
		{
		OffsetX		= -x;
		DrawClipped = TRUE;
		}

	if (y < 0)
		{
		OffsetY		= -y;
		DrawClipped = TRUE;
		}

	if (x + width >= WORK_WIDTH)		
		{
		OffsetW = (x + width) - WORK_WIDTH;
		DrawClipped = TRUE;
		}

	if (y + height >= WORK_HEIGHT)	
		{
		OffsetH = (y + height) - WORK_HEIGHT;
		DrawClipped = TRUE;
		}


	if (DrawClipped)
		{
		Source.left		= sx + OffsetX;
		Source.top		= sy + OffsetY;
		Source.right	= Source.left + width - OffsetX - OffsetW;
		Source.bottom	= Source.top + height - OffsetY - OffsetH;

		lpWork->BltFast(x + OffsetX, y + OffsetY, lpObject, &Source, DDBLTFAST_SRCCOLORKEY);
		}
	else
		{
		Source.left		= sx;
		Source.top		= sy;
		Source.right	= Source.left + width;
		Source.bottom	= Source.top + height;

		lpWork->BltFast(x + OffsetX, y + OffsetY, lpObject, &Source, DDBLTFAST_SRCCOLORKEY);
		}
	}