#include <windows.h>
#include "Person.h"


int CPerson::StandAnimFrame		= 0;
int CPerson::WalkAnimFrame[4]	= {0, 1, 0, 2};


ANIMATION	CPerson::StandAnim	= {&CPerson::StandAnimFrame,
								   0,
								   0,
								   0,
								   0,
								   2,
								   ANIM_INFINITE};


ANIMATION	CPerson::WalkAnim	= {CPerson::WalkAnimFrame,
								   0,
								   0,
								   3,
								   0, 
								   4,
								   ANIM_INFINITE};


ANIMATION	CPerson::DashAnim	= {CPerson::WalkAnimFrame,
								   0,
								   0,
								   3,
								   0, 
								   2,
								   ANIM_INFINITE};



void CPerson::DoLogic()
	{
	CGObject::DoLogic();


	if (X == DestX && Y == DestY)
		SetAnimation(&StandAnim, NULL);
	}




void CPerson::WalkLeftTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnLeft();

	SetAnimation(&WalkAnim, NULL);

	SpeedX = 1;
	SpeedY = 1;

	MoveLeftTile();
	}




void CPerson::WalkRightTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnRight();

	SetAnimation(&WalkAnim, NULL);

	SpeedX = 1;
	SpeedY = 1;

	MoveRightTile();
	}




void CPerson::WalkUpTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnUp();

	SetAnimation(&WalkAnim, NULL);

	SpeedX = 1;
	SpeedY = 1;

	MoveUpTile();
	}




void CPerson::WalkDownTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnDown();

	SetAnimation(&WalkAnim, NULL);

	SpeedX = 1;
	SpeedY = 1;

	MoveDownTile();
	}




void CPerson::DashLeftTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnLeft();

	SetAnimation(&DashAnim, NULL);

	SpeedX = 2;
	SpeedY = 2;

	MoveLeftTile();
	}



void CPerson::DashRightTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnRight();

	SetAnimation(&DashAnim, NULL);

	SpeedX = 2;
	SpeedY = 2;

	MoveRightTile();
	}



void CPerson::DashUpTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnUp();

	SetAnimation(&DashAnim, NULL);

	SpeedX = 2;
	SpeedY = 2;

	MoveUpTile();
	}




void CPerson::DashDownTile()
	{
	if (X != DestX || Y != DestY)
		return;


	TurnDown();

	SetAnimation(&DashAnim, NULL);

	SpeedX = 2;
	SpeedY = 2;

	MoveDownTile();
	}




void CPerson::Draw(int dx, int dy)
	{
	int sx, sy;


	if (Anim.pFrame)
		sx = (Anim.pFrame[Anim.Pos] * Width) + (Anim.pFrame[Anim.Pos] + 1);
	else
		sx = (Anim.Pos * Width) + (Anim.Pos + 1);


	switch(Dir)
		{
		case DIR_DOWN:
			sy = 1;
			break;

		case DIR_LEFT:
			sy = Height + 2;
			break;

		case DIR_RIGHT:
			sy = Height * 2 + 3;
			break;

		case DIR_UP:
			sy = Height * 3 + 4;
			break;
		}


	Draw_Object_To_Work(surfaceID, dx - (Width / 2), dy - (Height - (Height / 3)), sx, sy, Width, Height); 
	}