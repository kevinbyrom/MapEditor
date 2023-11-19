#ifndef __GObject_H
#define __GObject_H


#include "GFX.h"


#define ANIM_INFINITE		-1

#define DIR_UP				1
#define DIR_LEFT			2
#define DIR_RIGHT			4
#define DIR_DOWN			8



struct ANIMATION
	{
	int * pFrame;
	int Pos,
		Min,
		Max,
		Counter,
		CounterMax,
		Loop;
	};




class CGObject
	{
	public:

		CGObject()					{ surfaceID = 0; X = 0; X = 0; DestX = 0; DestY = 0;
									  State = 0; Dir = DIR_DOWN; Anim.pFrame = NULL; Anim.Pos = 0;
									}


		int surfaceID;				// Surface where the tile images is located
		int X, Y;					// X Y pos in world space
		int DestX, DestY;			// Destination X Y pos
		int SpeedX, SpeedY;			// Speed for x y changes
		int Width, Height;			// Width Height of the object
		
		int State;					// State of the object
		
		int Dir;					// Direction of the object

		ANIMATION Anim;				// Animation struct
		ANIMATION NextAnim;			// Next animation struct

		virtual void DoLogic();

		virtual void Draw(int dx, int dy) {};

		BOOL InRect(RECT * pRect);

		
	protected:

		void MoveLeftTile();	
		void MoveRightTile();	
		void MoveUpTile();		
		void MoveDownTile();

		void TurnLeft()				{ Dir = DIR_LEFT; }
		void TurnRight()			{ Dir = DIR_RIGHT; }
		void TurnUp()				{ Dir = DIR_UP; }
		void TurnDown()				{ Dir = DIR_DOWN; }

		void SetAnimation(ANIMATION * pAnim, ANIMATION * pNextAnim);
	};



#endif