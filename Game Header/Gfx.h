#ifndef __GFX_H
#define __GFX_H


#include "ddraw.h"


#define SCREEN_WIDTH		320
#define SCREEN_HEIGHT		240
#define SCREEN_BPP			8

#define TILEBMP_WIDTH		320
#define TILEBMP_HEIGHT		200

#define TILE_WIDTH			16	
#define TILE_HEIGHT			16

#define NUM_TILE_X			18
#define NUM_TILE_Y			12
#define MAX_TILE_NUM		NUM_TILE_X * NUM_TILE_Y

#define WORK_WIDTH			320
#define WORK_HEIGHT			240

#define WORK_X				0
#define WORK_Y				0

#define FONTSURF_WIDTH		320
#define FONTSURF_HEIGHT		240

#define TILE_POS_X(pos)		(int)(pos / TILE_WIDTH)
#define TILE_POS_Y(pos)		(int)(pos / TILE_HEIGHT)

#define OBJECTBMP_WIDTH		320
#define OBJECTBMP_HEIGHT	240

#define FONT_WIDTH		8
#define FONT_HEIGHT		8
#define FONT_SPACING	2



void Clear_Surface(LPDIRECTDRAWSURFACE4 lpSurface);
void Clear_Surface_To_Color(LPDIRECTDRAWSURFACE4 lpSurface, int color);

void Blit_Work_To_Back(int x, int y, int sx, int sy, int swidth, int sheight, int trans);

void Draw_HLine(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int x1, int y, int color);
void Draw_VLine(LPDIRECTDRAWSURFACE4 lpSurface, int x, int y0, int y1, int color);
void Draw_Rect(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int y0, int x1, int y1, int color);
void Draw_Rect_To_Work(int x0, int y0, int x1, int y1, int color);
void Draw_Fill_Rect(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int y0, int x1, int y1, int color);
void Draw_Frame_Rect(LPDIRECTDRAWSURFACE4 lpSurface, int x0, int y0, int x1, int y1, int color, int fillcolor);
void Draw_Gradient(LPDIRECTDRAWSURFACE4 lpSurface, int width, int height, int color1, int color2);

void Draw_Text(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x, int y);
void Draw_Text_Center(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x, int y);
void Draw_Text_Box(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x1, int y1, int x2, int y2);
void Draw_Text_Box_Center(LPDIRECTDRAWSURFACE4 lpSurface, char * strText, int x1, int y1, int x2, int y2);

void Draw_Tile_To_Work(UCHAR Tile, int x, int y, int Trans);
void Draw_Object_To_Work(int ImageID, int x, int y, int sx, int sy, int width, int height);

#endif