#include <windows.h>
#include "BlockMap.h"



void CBlockMap::SetMapSize(int width, int height)
	{
	int x, 
		y;

	int blockpos;

	UCHAR * newBlock = new UCHAR[width * height];



	// Default the maps to zero //

	memset(newBlock, BLOCK_ALLOW_ALL, width * height);


	for (y = 0; y < height; y++)
		for (x = 0; x < width; x++)
			{
			blockpos = x + (y * width);

			if (x < m_Width && y < m_Height)
				{
				if (m_Block)
					newBlock[blockpos] = m_Block[blockpos];			
				}
			}


	// Delete the previous maps //

	if (m_Block)
		delete m_Block;


	// Allocate new maps //

	m_Block = new UCHAR[width * height];


	// Copy the block info into the new maps //

	memcpy(m_Block, newBlock, width * height);


	// Set the new map size //

	CMap::SetMapSize(width, height);


	delete newBlock;
	}






UCHAR CBlockMap::GetBlock(int x, int y)
	{
	if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
		return 0;
	else
		return m_Block[x + (y * m_Width)];
	}






void CBlockMap::SetBlock(int x, int y, UCHAR block)
	{
	if (x >= 0 && x < m_Width && y >= 0 && y < m_Height)
		m_Block[x + (y * m_Width)] = block;
	}


