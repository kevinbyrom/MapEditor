#ifndef __DirectX_H
#define __DirectX_H


#include "ddraw.h"
#include "dinput.h"



// DIRECT DRAW OBJECTS 

extern LPDIRECTDRAW4			lpdd;
extern LPDIRECTDRAWSURFACE4		lpPrimary,
								lpBack,
								lpTile,
								lpWork,
								lpObject,
								lpFont;

extern LPDIRECTDRAWPALETTE	lpPalette;


// DIRECT INPUT OBJECTS 

extern LPDIRECTINPUT lpDInput;

extern LPDIRECTINPUTDEVICE lpKeyboard;




struct BITMAP_FILE
	{
	BITMAP_FILE()			{ buffer = NULL; }

	BITMAPFILEHEADER bitmapfileheader;
	BITMAPINFOHEADER bitmapinfoheader;
	
	PALETTEENTRY palette[256];

	UCHAR * buffer;
	};



int InitDirectX();
void ShutDownDirectX();

int CreateOffScreenSurface(LPDIRECTDRAWSURFACE4 * lplpSurface, int width, int height, int colorkey = -1);

int Load_Bitmap_File(BITMAP_FILE * bitmap, char * filename);
int Unload_Bitmap_File(BITMAP_FILE * bitmap);
int Flip_Bitmap(UCHAR *image, int bytes_per_line, int height);
void Draw_Bitmap_To_Surface(BITMAP_FILE * bitmap, LPDIRECTDRAWSURFACE4 lpSurface);


#endif