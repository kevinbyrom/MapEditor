#ifndef __Map_H
#define __Map_H



class CMap
	{
	public:

		CMap()												{ SetMapSize(0,0); }

		virtual void SetMapSize(int width, int height)		{ m_Width = width; m_Height = height; }
		//virtual void Load(CFile * pFile)					{}
		//virtual void Save(CFile * pFile)					{}


	protected:

		int m_Width, m_Height;
	};



#endif