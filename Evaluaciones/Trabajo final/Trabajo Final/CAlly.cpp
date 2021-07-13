#include "CAlly.h"

CAlly::CAlly(int w, int h, Graphics^g) : CMovementBase(g, w, h)
{
	dx = rand() % (15 - 5 + 1) + 5;
	dy = rand() % (10 - 5 + 1) + 5;
	movAuxdx = dx;
	movAuxdy = dy;
	help = 2000;
	pursued = 0;
}

CAlly::~CAlly()
{
	delete clock;
}

void CAlly::move(Graphics^ g, CHabitant* habitant)
{
	if (x == habitant->get_x())
	{
		x += 0; idX = 0;
	}
	if (y == habitant->get_y())
	{
		y += 0; idY = 0;
	}
	if (x > habitant->get_x())
	{
		x -= dx; idY = 1; idX++;
	}
	if (x < habitant->get_x())
	{
		x += dx; idY = 2; idX++;
	}
	if (y > habitant->get_y())
	{
		y -= dy; idY = 3; idX++;
	}
	if (y < habitant->get_y())
	{
		y += dy; idY = 0; idX++;
	}
	if (idX > 3)idX = 0;
}

int CAlly::get_mAuxdx()
{
	return this->movAuxdx;
}

int CAlly::get_mAuxdy()
{
	return this->movAuxdy;
}

void CAlly::set_pursued(int New)
{
	this->pursued = New;
}

int CAlly::get_pursued()
{
	return this->pursued;
}

void CAlly::set_help(int New)
{
	this->help = New;
}

int CAlly::get_help()
{
	return this->help;
}

void CAlly::add_clock(int w,int h,Graphics^g, int x, int y)
{
	clock = new CClock(w, h, g);
	clock->set_x(x);
	clock->set_y(y);
}

CClock* CAlly::get_clock()
{
	return this->clock;
}

