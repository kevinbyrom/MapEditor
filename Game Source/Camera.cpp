#include <windows.h>
#include "Camera.h"




void CCamera::DoLogic()
	{
	// If attached to an object then change x, y to object x and y //

	if (m_pObject)
		{
		X		= m_pObject->X + m_OffsetX;
		Y		= m_pObject->Y + m_OffsetY;
		DestX	= m_pObject->DestX + m_OffsetX;
		DestY	= m_pObject->DestY + m_OffsetY;
		}
	}





void CCamera::SlowPanLeftTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveLeftTile();
	}





void CCamera::SlowPanRightTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveRightTile();
	}





void CCamera::SlowPanUpTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveUpTile();
	}





void CCamera::SlowPanDownTile()
	{
	if (X != DestX || Y != DestY)
		return;

	SpeedX = 1;
	SpeedY = 1;

	MoveDownTile();
	}