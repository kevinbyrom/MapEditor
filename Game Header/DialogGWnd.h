#ifndef __DialogGWnd_H
#define __DialogGWnd_H


#include "GWnd.h"


class CDialogGWnd : public CGWnd
	{
	public:

	protected:

		char strDialogText[256];

		virtual void OnDraw(LPDIRECTDRAWSURFACE lpSurface);
	};



#endif