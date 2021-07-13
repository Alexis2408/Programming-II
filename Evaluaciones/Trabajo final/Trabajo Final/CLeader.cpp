#include "CLeader.h"

CLeader::CLeader(int w, int h,Graphics^ g) : CMovementBase(g,w,h)
{
	ezoom = 0.5;
	score = 0;
}

CLeader::~CLeader()
{

}


void CLeader::move(Graphics^ g)
{
	if (dx > 0)
		idY = 0;
	else if (dx < 0)
		idY = 0;
	else if (dy > 0)
		idY = 0;
	else if (dy < 0)
		idY = 0;
	if (dx < 0)
		idY = 1;
	if (dx > 0)
		idY = 2;
	if (dy < 0)
		idY = 3;
	if (dy > 0)
		idY = 0;
	if (dx != 0 || dy != 0)
	{
		idX++;
		if (idX == 4)
			idX = 0;
	}
	x += dx;
	y += dy;
	dx = dy = 0;

}

void CLeader::set_score(int New)
{
	this->score = New;
}

int CLeader::get_score()
{
	return this->score;
}

