 
	 
#include <windows.h>
#include "Level.h"




void CLevel::SetLevelSize(int width, int height)
	{
	m_Width		= width;
	m_Height	= height;


	TileMap.SetMapSize(width, height);
	BlockMap.SetMapSize(width, height);
	}