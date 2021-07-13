#include "CWall.h"

CWall::CWall(int w, int h): CMovementBase(w,h)
{
	frecuence = 0;
}

CWall::~CWall()
{
}

void CWall::show(Graphics^ g, Bitmap^ bmp)
{
	frecuence++;
	if (frecuence >= 10)
	{
		frecuence = 0;
		idX++;
		if (idX > 3)
		{
			idX = 0;
			idY++;
			if (idY > 3)
				idY = 0;
		}
	}
	Rectangle sectionShow = Rectangle(w * idX, h * idY, w, h);
	Rectangle zoom = Rectangle(x, y, w * ezoom, h * ezoom);
	g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
}
