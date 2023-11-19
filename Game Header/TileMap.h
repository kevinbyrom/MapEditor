#ifndef __TileMap_H
#define __TileMap_H


#include "Map.h"


#define INVALID_TILE		255


class CTileMap : public CMap
	{
	public:

		CTileMap();

		virtual void SetMapSize(int width, int height);

		UCHAR GetLvl1Tile(int x, int y);
		UCHAR GetLvl2Tile(int x, int y);
		UCHAR GetLvl3Tile(int x, int y);

		void SetLvl1Tile(int x, int y, UCHAR tile);
		void SetLvl2Tile(int x, int y, UCHAR tile);
		void SetLvl3Tile(int x, int y, UCHAR tile);

	protected:

		UCHAR * m_Lvl1,
			  * m_Lvl2,
			  * m_Lvl3;
	};



#endif