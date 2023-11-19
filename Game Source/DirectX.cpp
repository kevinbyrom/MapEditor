#include <windows.h>
#include <stdio.h>
#include <io.h>
#include "DirectX.h"
#include "Gfx.h"
#include "..\\WinMain.h"

#define BITMAP_ID			0x4D42
#define MAX_COLORS_PALETTE	256


LPDIRECTDRAW4				lpdd		= NULL;
LPDIRECTDRAWSURFACE4		lpPrimary	= NULL,
							lpBack		= NULL,
							lpTile		= NULL,
							lpWork		= NULL,
							lpObject	= NULL,
							lpFont		= NULL;

LPDIRECTDRAWPALETTE			lpPalette	= NULL;

LPDIRECTINPUT				lpDInput	= NULL;
LPDIRECTINPUTDEVICE			lpKeyboard	= NULL;




int InitDirectX()
	{
	LPDIRECTDRAW lptempdd;
	DDSURFACEDESC2 ddsd;
	PALETTEENTRY BlackPal[256];


	// Create the direct draw object //

	if (FAILED(DirectDrawCreate(NULL, &lptempdd, NULL)))
		return FALSE;


	// Get the latest interface //

	if (FAILED(lptempdd->QueryInterface(IID_IDirectDraw4, (LPVOID *)&lpdd)))
		{
		lptempdd->Release();
		return FALSE;
		}


	// Set the cooperation level //

	lptempdd->Release();

#ifdef FULLSCREEN
	if (FAILED(lpdd->SetCooperativeLevel(MainWnd, DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE)))
		return FALSE;
#else
	if (FAILED(lpdd->SetCooperativeLevel(MainWnd, DDSCL_NORMAL)))
		return FALSE;
#endif


	// Set the display mode //

#ifdef FULLSCREEN
	if (FAILED(lpdd->SetDisplayMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, 0, 0)))
		return FALSE;



	// Create the main palette//

	memset(BlackPal, 0, sizeof(PALETTEENTRY) * 256);

	if (FAILED(lpdd->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256 | DDPCAPS_INITIALIZE, BlackPal, &lpPalette, NULL)))
		return FALSE;
#endif


	// Now create the primary surface //

	memset(&ddsd, 0, sizeof(ddsd));

	ddsd.dwSize = sizeof(ddsd);

#ifdef FULLSCREEN
	ddsd.dwFlags			= DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
	ddsd.dwBackBufferCount	= 1;
	ddsd.ddsCaps.dwCaps		= DDSCAPS_PRIMARYSURFACE | DDSCAPS_COMPLEX | DDSCAPS_FLIP;
#else
	ddsd.dwFlags			= DDSD_CAPS;
	ddsd.ddsCaps.dwCaps		= DDSCAPS_PRIMARYSURFACE;
#endif
	if (FAILED(lpdd->CreateSurface(&ddsd, &lpPrimary, NULL)))
		return FALSE;
		


	// Set the palette to the primary surface //

#ifdef FULLSCREEN
	if (FAILED(lpPrimary->SetPalette(lpPalette)))
		return FALSE;
#endif


	// Create the back surface //

#ifdef FULLSCREEN
	ddsd.ddsCaps.dwCaps	= DDSCAPS_BACKBUFFER;

	if (FAILED(lpPrimary->GetAttachedSurface(&ddsd.ddsCaps, &lpBack)))
		return FALSE;
#endif


	// Create a tile, work and font surface //


	if (!CreateOffScreenSurface(&lpTile, TILEBMP_WIDTH, TILEBMP_HEIGHT, 0))
		return FALSE;
	
	if (!CreateOffScreenSurface(&lpWork, WORK_WIDTH, WORK_HEIGHT, 0))
		return FALSE;

	if (!CreateOffScreenSurface(&lpObject, OBJECTBMP_WIDTH, OBJECTBMP_WIDTH, 0))
		return FALSE;

	if (!CreateOffScreenSurface(&lpFont, FONTSURF_WIDTH, FONTSURF_HEIGHT, 0))
		return FALSE;
	



	// Create the Direct Input object //

	if (FAILED(DirectInputCreate(MainInst, DIRECTINPUT_VERSION, &lpDInput, NULL)))
		{
		OutputDebugString("FAILED TO CREATE DINPUT\n\r");
		return FALSE;
		}


	// Create the keyboard device //

	if (FAILED(lpDInput->CreateDevice(GUID_SysKeyboard, &lpKeyboard, NULL)))
		{
		OutputDebugString("FAILED TO CREATE KEYBOARD\n\r");
		return FALSE;
		}


	// Set the keyboard cooperation //

	if (FAILED(lpKeyboard->SetCooperativeLevel(MainWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE)))
		{
		OutputDebugString("FAILED TO SET KEYBOARD COOP LEVEL\n\r");
		return FALSE;
		}


	// Set the keyboard data format //

	if (FAILED(lpKeyboard->SetDataFormat(&c_dfDIKeyboard)))
		{
		OutputDebugString("FAILED TO SET KEYBOARD DATA FORMAT\n\r");
		return FALSE;
		}


	// Acquire the keyboard //

	if (FAILED(lpKeyboard->Acquire()))
		{
		OutputDebugString("FAILED TO ACQUIRE KEYBOARD\n\r");
		return FALSE;
		}


	return TRUE;
	}





void ShutDownDirectX()
	{
	if (lpdd)
		lpdd->RestoreDisplayMode();
		
	if (lpPrimary)
		lpPrimary->Release();

	if (lpTile)
		lpTile->Release();

	if (lpWork)
		lpWork->Release();

	if (lpObject)
		lpObject->Release();

	if (lpFont)
		lpFont->Release();

	if (lpdd)
		lpdd->Release();

	if (lpKeyboard)
		lpKeyboard->Release();

	if (lpDInput)
		lpDInput->Release();
	}





int CreateOffScreenSurface(LPDIRECTDRAWSURFACE4 * lplpSurface, int width, int height, int colorkey)
	{
	DDSURFACEDESC2 ddsd;
	DDCOLORKEY ddcolorkey;

	
	memset(&ddsd, 0, sizeof(ddsd));

	ddsd.dwSize			= sizeof(ddsd);
	ddsd.dwFlags		= DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_CKSRCBLT;
	ddsd.dwWidth		= width;
	ddsd.dwHeight		= height;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;


	if (FAILED(lpdd->CreateSurface(&ddsd, lplpSurface, NULL)))
		{
		OutputDebugString("COULD NOT CREATE THE SURFACE\n\r");
		return FALSE;
		}


	if (colorkey > -1)
		{
		ddcolorkey.dwColorSpaceLowValue		= colorkey;
		ddcolorkey.dwColorSpaceHighValue	= colorkey;

		(*lplpSurface)->SetColorKey(DDCKEY_SRCBLT, &ddcolorkey);
		}


	return TRUE;
	}






int Load_Bitmap_File(BITMAP_FILE * bitmap, char * filename)
	{
	int file_handle,
		index;

	UCHAR * temp_buffer = NULL;
	OFSTRUCT file_data;
	int temp_color;



	if ((file_handle = OpenFile(filename, &file_data, OF_READ)) == -1)
		{
		OutputDebugString("COULD NOT FIND\\LOAD BITMAP FILE!\n\r");
		return 0;
		}


	_lread(file_handle, &bitmap->bitmapfileheader, sizeof(BITMAPFILEHEADER));


	if (bitmap->bitmapfileheader.bfType != BITMAP_ID)
		{
		_lclose(file_handle);

		return 0;
		}



	_lread(file_handle, &bitmap->bitmapinfoheader, sizeof(BITMAPINFOHEADER));


	if (bitmap->bitmapinfoheader.biBitCount == 8)
		{
		_lread(file_handle, &bitmap->palette, MAX_COLORS_PALETTE * sizeof(PALETTEENTRY));


		for (index = 0; index < MAX_COLORS_PALETTE; index++)
			{
			temp_color						= bitmap->palette[index].peRed;
			bitmap->palette[index].peRed	= bitmap->palette[index].peBlue;
			bitmap->palette[index].peBlue	= temp_color;

			bitmap->palette[index].peFlags	= PC_NOCOLLAPSE;
			}
		}



	bitmap->bitmapinfoheader.biSizeImage = (bitmap->bitmapinfoheader.biWidth * bitmap->bitmapinfoheader.biHeight) * (bitmap->bitmapinfoheader.biBitCount / 8);


	_lseek(file_handle, -(int)(bitmap->bitmapinfoheader.biSizeImage), SEEK_END);


	if (bitmap->bitmapinfoheader.biBitCount==8 ||
		bitmap->bitmapinfoheader.biBitCount==16 ||
		bitmap->bitmapinfoheader.biBitCount==24)
		{
		if (bitmap->buffer)
			free(bitmap->buffer);


		if (!(bitmap->buffer = (UCHAR *)malloc(bitmap->bitmapinfoheader.biSizeImage)))
			{
			_lclose(file_handle);

			return 0;
			}


		_lread(file_handle, bitmap->buffer, bitmap->bitmapinfoheader.biSizeImage);		
		}
	else
		{
		return 0;
		}


	_lclose(file_handle);


	Flip_Bitmap(bitmap->buffer,
				bitmap->bitmapinfoheader.biWidth *
				(bitmap->bitmapinfoheader.biBitCount / 8),
				bitmap->bitmapinfoheader.biHeight);


	return 1;
	}




int Unload_Bitmap_File(BITMAP_FILE * bitmap)
	{
	if (bitmap->buffer)
		{
		free(bitmap->buffer);

		bitmap->buffer = NULL;
		}

	return 1;
	}




int Flip_Bitmap(UCHAR *image, int bytes_per_line, int height)
	{
	UCHAR *buffer = NULL; 
	int size;
	int index;     


	// allocate the temporary buffer
	
	size = bytes_per_line * height;

	if (!(buffer = (UCHAR *)malloc(size)))
		return 0;


	// copy image to work area
	
	memcpy(buffer,image,size);


	// flip vertically
	
	for (index=0; index < height; index++)
		memcpy(&image[((height-1) - index)*bytes_per_line],
			   &buffer[index*bytes_per_line], bytes_per_line);


	// release the memory
	
	free(buffer);


	// return success

	return 1;
	} 






void Draw_Bitmap_To_Surface(BITMAP_FILE * bitmap, LPDIRECTDRAWSURFACE4 lpSurface)
	{
	DDSURFACEDESC2 ddsd;
	int Pitch, x, y, pixelpos;
	UCHAR * pData;


	if (!lpSurface || !bitmap)
		return;


	// Lock the surface //
	memset(&ddsd, 0, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	lpSurface->Lock(NULL,&ddsd,DDLOCK_WAIT | DDLOCK_SURFACEMEMORYPTR,NULL); 


	// Set the memory pitch //
	Pitch = ddsd.lPitch;


	// Get pointer to surface

	pData = (UCHAR *)ddsd.lpSurface;


	// Copy the data from the bitmap to the surface //

	for (y = 0; y < bitmap->bitmapinfoheader.biHeight; y++)
		for (x = 0; x < bitmap->bitmapinfoheader.biWidth; x++)
			{
			pixelpos = x + (Pitch * y);
			pData[pixelpos] = bitmap->buffer[pixelpos];
			}


	// Unlock the surface //

	lpSurface->Unlock(NULL);
	}






