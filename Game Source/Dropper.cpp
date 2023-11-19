#include <windows.h>
#include "Dropper.h"
#include "Gfx.h"




CDropper::CDropper() : CGObject()
	{
	X		= 8; 
	Y		= 8; 

	DestX	= 8; 
	DestY	= 8; 

	Width	= TILE_WIDTH;
	Height	= TILE_HEIGHT;

	m_Color	= 15;
	}




void CDropper::SlowPanLeftTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveLeftTile();
	}





void CDropper::SlowPanRightTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveRightTile();
	}





void CDropper::SlowPanUpTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveUpTile();
	}





void CDropper::SlowPanDownTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveDownTile();
	}




void CDropper::Draw(int dx, int dy)
	{
	int halfwidth, 
		halfheight;


	halfwidth	= Width / 2;
	halfheight	= Height / 2;

	Draw_Rect_To_Work(dx - halfwidth, dy - halfheight, dx + halfwidth - 1, dy + halfheight - 1, m_Color);
	}




void CDropper::ChangeColor()
	{
	m_Color++;

	if (m_Color > 15)
		m_Color = 2;
	}