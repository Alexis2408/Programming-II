#pragma once
#include "CAnimal.h"
//Johan CPP
class CCaballo : public CAnimal {
private:
	int color;
public:
	CCaballo(int ancho, int alto) : CAnimal(ancho, alto) {
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
		do
		{
			dx = (rand() % 3 - 1) * 5;
			dy = (rand() % 3 - 1) * 5;
		} while (dx == 0 && dy == 0);
		color = 0;
		idx = 0;
	}

	~CCaballo() {}
	void mover(Graphics^ g)
	{
		if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
		if (y + alto * 1.0 > g->VisibleClipBounds.Height || y < 0) dy *= -1;
		

		if (color == 0)
		{
			if (dx > 0) 
				idy = 2;
			if (dx < 0)
				idy = 1;
			if (dy > 0)
				idy = 0;
			if (dy < 0)
				idy = 3;
			if (idx > 3) idx = 0;
		}
		if (color == 1)
		{
			if (dx > 0)
				idy = 6;
			if (dx < 0)
				idy = 5;
			if (dy > 0)
				idy = 4;
			if (dy < 0)
				idy = 7;
			if (idx > 3) idx = 0;
		}
		if (color == 2)
		{
			if (dx > 0)
				idy = 2;
			if (dx < 0)
				idy = 1;
			if (dy > 0)
				idy = 0;
			if (dy < 0)
				idy = 3;
			idx = 3;
			if (idx > 6) idx = 6;
		}
		if (color == 3)
		{
			if (dx > 0) {
				idy = 7;
			}
			else {
				idy = 5;
			}

			if (dy > 0) {
				idy = 4;
			}
			else {
				idy = 6;
			}
			idx = 3;
			if (idx > 6) idx = 3;
		}
		y += dy;
		x += dx;
		idx++;

	}
	void setColor(int color)
	{
		this->color = color;
	}
};
