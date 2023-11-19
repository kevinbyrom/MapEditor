#include <windows.h>
#include "Gfx.h"
#include "GWnd.h"



int CGWnd::Create(int x, int y, int width, int height, int backstyle, int borderstyle)
	{
	m_X			= x;
	m_Y			= y;
	m_Width		= width;
	m_Height	= height;

	m_BackStyle		= backstyle;
	m_BorderStyle	= borderstyle;


	return 1;
	}





void CGWnd::Draw(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	Draw_Fill_Rect(lpSurface, 0, 0, m_Width, m_Height, 0);


	// Draw the back based on the style //

	if (m_BackStyle == GWND_BACK_COLOR)
		DrawBackColor(lpSurface);
	else if (m_BackStyle == GWND_BACK_GRADIENT)
		DrawBackGradient(lpSurface);



	// Call the virtual OnDraw //

	OnDraw(lpSurface);


	// Draw the border based on the style //

	if (m_BorderStyle == GWND_BORDER_THIN)
		DrawBorderThin(lpSurface);


	// Blit the work surface to the back surface //

	if (m_BackStyle == GWND_BACK_NONE)
		Blit_Work_To_Back(m_X, m_Y, 0, 0, m_Width, m_Height, TRUE);
	else
		Blit_Work_To_Back(m_X, m_Y, 0, 0, m_Width, m_Height, FALSE);
	}






void CGWnd::DrawBackColor(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	Clear_Surface_To_Color(lpSurface, 1);
	}






void CGWnd::DrawBackGradient(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	Draw_Gradient(lpSurface, m_Width, m_Height, 232, 254);
	}






void CGWnd::DrawBorderThin(LPDIRECTDRAWSURFACE4 lpSurface)
	{
	Draw_Rect(lpSurface, 0, 0, m_Width - 1, m_Height - 1, 15);
	}






