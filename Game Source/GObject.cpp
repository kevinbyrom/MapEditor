#include <windows.h>
#include "GObject.h"
#include "Gfx.h"




void CGObject::DoLogic()
	{
	Anim.Counter++;

	if (Anim.Counter >= Anim.CounterMax)
		{
		Anim.Counter = 0;

		// Increment the animation frame //

		if (Anim.Loop > 0)
			{
			Anim.Pos++;

			if (Anim.Pos > Anim.Max)
				{
				Anim.Pos = Anim.Min;
				Anim.Loop--;

				
				// If the current animation is done, then change to the next animation //

				if (Anim.Loop == 0)
					memcpy(&Anim, &NextAnim, sizeof(ANIMATION));
				}
			}



		if (Anim.Loop == ANIM_INFINITE)
			{
			Anim.Pos++;

			if (Anim.Pos > Anim.Max)
				Anim.Pos = Anim.Min;
			}
		}



	// Move the position if the destination is different than the current //

	if (X != DestX)
		{
		if (X < DestX)
			{
			X += SpeedX;

			if (X > DestX)
				X = DestX;
			}
		else
			{
			X -= SpeedX;

			if (X < DestX)
				X = DestX;
			}
		}



	if (Y != DestY)
		{
		if (Y < DestY)
			{
			Y += SpeedY;

			if (Y > DestY)
				Y = DestY;
			}
		else
			{
			Y -= SpeedY;

			if (Y < DestY)
				Y = DestY;
			}
		}
	}







void CGObject::SetAnimation(ANIMATION * pAnim, ANIMATION * pNextAnim)
	{
	memcpy(&Anim, pAnim, sizeof(ANIMATION));

	if (pNextAnim)
		memcpy(&NextAnim, pNextAnim, sizeof(ANIMATION));
	}






void CGObject::MoveLeftTile()			
	{ 
	DestX = X - TILE_WIDTH; 
	}





void CGObject::MoveRightTile()		
	{ 
	DestX = X + TILE_WIDTH; 
	}





void CGObject::MoveUpTile()			
	{ 
	DestY = Y - TILE_HEIGHT; 
	}





void CGObject::MoveDownTile()		
	{ 
	DestY = Y + TILE_HEIGHT; 
	}






BOOL CGObject::InRect(RECT * pRect)
	{
	int halfwidth, halfheight;


	halfwidth	= Width / 2;
	halfheight	= Height / 2;


	if (X + halfwidth < pRect->left ||
		X - halfwidth >= pRect->right ||
		Y + halfheight < pRect->top ||
		Y - halfheight >= pRect->bottom)
		return FALSE;


	return TRUE;
	}