#include "CExtra.h"

CExtra::CExtra(int w, int h, Graphics^ g): CMovementBase(g,w,h)
{
	dx = rand() % (8 - 3 + 1) + 3;
	dy = rand() % (3 - 1 + 1) + 1;
}

CExtra::~CExtra()
{
}

void CExtra::move(Graphics^ g, int level)
{
	if (x + dx<g->VisibleClipBounds.Left || x + dx + w>g->VisibleClipBounds.Right)
		dx *= -1;
	if (y + dy<g->VisibleClipBounds.Top || y + dy + h>g->VisibleClipBounds.Bottom)
		dy *= -1;
	if (level == 1)
	{
		idX++;
		if (idX == 4)
			idX = 0;
	}
	x += dx;
	y += dy;
}

void CExtra::boom()
{
	idX++;
	if (idX >= 3)
	{
		idX = 1;
	}
}
