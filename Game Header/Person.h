#ifndef __Person_H
#define __Person_H


#include "GObject.h"


#define PERSON_STANDING			0
#define PERSON_WALKING			1
#define PERSON_RUNNING			2


class CPerson : public CGObject
	{
	public:

		CPerson() : CGObject()	{ X = 8; Y = 8; DestX = 8; DestY = 8; Width = 16; Height = 24; }

		virtual void DoLogic();

		void WalkLeftTile();
		void WalkRightTile();
		void WalkUpTile();
		void WalkDownTile();

		void DashLeftTile();
		void DashRightTile();
		void DashUpTile();
		void DashDownTile();

		virtual void Draw(int dx, int dy);


	protected:

		static int StandAnimFrame;
		static int WalkAnimFrame[4];

		static ANIMATION StandAnim;
		static ANIMATION WalkAnim;
		static ANIMATION DashAnim;
	};



#endif