#ifndef __Dropper_H
#define __Dropper_H


#include "GObject.h"


class CDropper: public CGObject
	{
	public:

		CDropper();		

		void SlowPanLeftTile();
		void SlowPanRightTile();
		void SlowPanUpTile();
		void SlowPanDownTile();

		virtual void Draw(int dx, int dy);

		void ChangeColor();


	protected:

		int m_Color;
	};



#endif