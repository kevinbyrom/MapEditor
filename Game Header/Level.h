#ifndef	__Level_H
#define __Level_H


#include "TileMap.h"
#include "BlockMap.h"


#define MAX_LEVEL_WIDTH			1024
#define MAX_LEVEL_HEIGHT		1024



class CLevel
	{
	public:

		CTileMap	TileMap;
		CBlockMap	BlockMap;


		void SetLevelSize(int width, int height);


		int GetWidth()			{ return m_Width; }
		int GetHeight()			{ return m_Height; }


	protected:

		int m_Width, m_Height;

		char m_strLevelName[256];
		char m_strTileMapName[256];
		char m_strBlockMapName[256];

		char m_strTileBmp[256];
	};



#endif