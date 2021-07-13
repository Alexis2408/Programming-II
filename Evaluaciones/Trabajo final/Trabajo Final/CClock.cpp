#include "CClock.h"

CClock::CClock(int w, int h, Graphics^ g) : CMovementBase(g, w, h)
{
	dx = dy = idX = idY = 0;
}

CClock::~CClock()
{
}

void CClock::showv2(Graphics^ g, Bitmap^ img)
{
	idX++;
	if (idX >= 5)
		idX = 0;
	Rectangle section = Rectangle(idX * w, idY * h, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.08, h * 0.08);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}
