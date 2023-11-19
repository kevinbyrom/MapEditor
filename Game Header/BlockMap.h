#ifndef __BlockMap_H
#define __BlockMap_H


#include "Map.h"


#define BLOCK_ALLOW_NONE		0
#define BLOCK_ALLOW_ALL			1
#define BLOCK_ALLOW_LVL1		2
#define BLOCK_ALLOW_LVL2		3
#define BLOCK_ALLOW_LVL3		4
		


class CBlockMap : public CMap
	{
	public:

		virtual void SetMapSize(int width, int height);

		UCHAR GetBlock(int x, int y);

		void SetBlock(int x, int y, UCHAR block);


	protected:

		UCHAR * m_Block;
	};



#endif