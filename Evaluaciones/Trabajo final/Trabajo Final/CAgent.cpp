#include "CAgent.h"

CAgent::CAgent(int w, int h, Graphics^ g) : CMovementBase(g, w, h)
{
	dx = rand() % (4 - 1 + 1) + 1;
	dy = rand() % (4 - 1 + 1) + 1;
	frequency = 0;
}

CAgent::~CAgent(){}
void CAgent::move(Graphics^ g, Bitmap^ WallImg, CAlly* ally, bool exist)
{
	if (exist)
	{
		dx = (rand() % (3) + 1);
		dy = (rand() % (3) + 1);
		if (x > g->VisibleClipBounds.Left + (WallImg->Width / 4) && x > ally->get_x())
		{
			x -= dx; idY = 1;
		}
		if (x + dx < g->VisibleClipBounds.Width - (WallImg->Height / 4) && x < ally->get_x())
		{
			x += dx; idY = 2;
		} 
		if (y > g->VisibleClipBounds.Top + (WallImg->Height / 4) && y > ally->get_y())
		{
			y -= dy; idY = 3;
		}
		if (y + dy < g->VisibleClipBounds.Height - (WallImg->Height / 4) && y < ally->get_y())
		{
			y += dy; idY = 0;
		}
		idX++;
		if (idX >= 4)
			idX = 0;
	}
	else {
		frequency++;
		if (frequency >= 1000)
		{
			dx = (rand() % (2) * 10 - 5) * 2;
			dy = (rand() % (2) * 10 - 5) * 2;
		}
		if (frequency >= 2000)
		{
			dx = rand() % (4 - 1 + 1) + 1;
			dy = rand() % (4 - 1 + 1) + 1;
			frequency = 0;
		}
		
		x += dx;
		y += dy;
		if (dx > 0)
			idY = 2;
		else if (dx < 0)
			idY = 1;
		else if (dy > 0)
			idY = 0;
		else if (dy < 0)
			idY = 3;
		idX++;
		if (idX >= 4)
			idX = 0;
	}

}

void CAgent::changeDirection()
{
	dx *= -1;
	dy *= -1;
}
