#ifndef __GWnd
#define __GWnd


#include "ddraw.h"


#define GWND_BACK_NONE		0
#define GWND_BACK_COLOR		1
#define GWND_BACK_GRADIENT	2

#define GWND_BORDER_NONE	0
#define GWND_BORDER_THIN	1


class CGWnd
	{
	public:

		virtual int Create(int x, int y, int width, int height, int backstyle, int borderstyle);

		void Draw(LPDIRECTDRAWSURFACE4 lpSurface);


	protected:

		int m_X,
			m_Y,
			m_Width,
			m_Height,
			m_BorderStyle,
			m_BackStyle;

		virtual void OnDraw(LPDIRECTDRAWSURFACE4 lpSurface) {}

		void DrawBackColor(LPDIRECTDRAWSURFACE4 lpSurface);
		void DrawBackGradient(LPDIRECTDRAWSURFACE4 lpSurface);

		void DrawBorderThin(LPDIRECTDRAWSURFACE4 lpSurface);
	};


#endif