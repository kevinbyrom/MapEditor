#ifndef __Camera_H
#define __Camera_H


#include "GObject.h"


class CCamera : public CGObject
	{
	public:

		CCamera()				{ X = 8; Y = 8; DestY = 8; DestY = 8; m_pObject = NULL; }

		virtual void DoLogic();

		void Attach(CGObject * pObject, int OffsetX = 0, int OffsetY = 0)		{ m_pObject = pObject; m_OffsetX = OffsetX; m_OffsetY = OffsetY; }
		void Detach()						{ m_pObject = NULL; }

		void SlowPanLeftTile();
		void SlowPanRightTile();
		void SlowPanUpTile();
		void SlowPanDownTile();


	protected:
		
		CGObject * m_pObject;

		int m_OffsetX, m_OffsetY;
	};



#endif