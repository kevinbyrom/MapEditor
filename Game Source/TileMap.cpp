#include <windows.h>
#include "TileMap.h"



CTileMap::CTileMap()
	{
	m_Lvl1 = NULL;
	m_Lvl2 = NULL;
	m_Lvl3 = NULL;
	}





void CTileMap::SetMapSize(int width, int height)
	{
	int x, 
		y;

	int newtilepos, tilepos;


	// Allocate new map arrays //

	UCHAR * newLvl1 = new UCHAR[width * height];
	UCHAR * newLvl2 = new UCHAR[width * height];
	UCHAR * newLvl3 = new UCHAR[width * height];


	// Default the maps to zero //

	memset(newLvl1, 0, width * height);
	memset(newLvl2, INVALID_TILE, width * height);
	memset(newLvl3, INVALID_TILE, width * height);


	if (m_Lvl1 || m_Lvl2 || m_Lvl3)
		{
		for (y = 0; y < height; y++)
			for (x = 0; x < width; x++)
				{
				newtilepos	= x + (y * width);
				tilepos		= x + (y * m_Width);

				if (x < m_Width && y < m_Height)
					{
					if (m_Lvl1)
						newLvl1[newtilepos] = m_Lvl1[tilepos];			

					if (m_Lvl2)
						newLvl2[newtilepos] = m_Lvl2[tilepos];

					if (m_Lvl3)
						newLvl3[newtilepos] = m_Lvl3[tilepos];
					}
				}
		}


	// Delete the previous maps //

	if (m_Lvl1)
		delete m_Lvl1;

	if (m_Lvl2)
		delete m_Lvl2;

	if (m_Lvl3)
		delete m_Lvl3;


	// Allocate new maps //

	m_Lvl1 = new UCHAR[width * height];
	m_Lvl2 = new UCHAR[width * height];
	m_Lvl3 = new UCHAR[width * height];


	// Copy the block info into the new maps //

	memcpy(m_Lvl1, newLvl1, width * height);
	memcpy(m_Lvl2, newLvl2, width * height);
	memcpy(m_Lvl3, newLvl3, width * height);


	// Set the new map size //

	CMap::SetMapSize(width, height);


	delete newLvl1;
	delete newLvl2;
	delete newLvl3;
	}






UCHAR CTileMap::GetLvl1Tile(int x, int y)
	{
	if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
		return INVALID_TILE;
	else
		return m_Lvl1[x + (y * m_Width)];
	}






UCHAR CTileMap::GetLvl2Tile(int x, int y)
	{
	if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
		return INVALID_TILE;
	else
		return m_Lvl2[x + (y * m_Width)];
	}






UCHAR CTileMap::GetLvl3Tile(int x, int y)
	{
	if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
		return INVALID_TILE;
	else
		return m_Lvl3[x + (y * m_Width)];
	}






void CTileMap::SetLvl1Tile(int x, int y, UCHAR tile)
	{
	if (x >= 0 && x < m_Width && y >= 0 && y < m_Height)
		m_Lvl1[x + (y * m_Width)] = tile;
	}






void CTileMap::SetLvl2Tile(int x, int y, UCHAR tile)
	{
	if (x >= 0 && x < m_Width && y >= 0 && y < m_Height)
		m_Lvl2[x + (y * m_Width)] = tile;
	}






void CTileMap::SetLvl3Tile(int x, int y, UCHAR tile)
	{
	if (x >= 0 && x < m_Width && y >= 0 && y < m_Height)
		m_Lvl3[x + (y * m_Width)] = tile;
	}