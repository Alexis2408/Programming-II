#pragma once
#include "CAnimal.h"
class CAguila : public CAnimal {
private:

public:
	CAguila(int ancho, int alto) : CAnimal(ancho, alto) {
		dy = 0;
		dx = 15 ;
		x = rand() % 60 * 10;
		y = rand() % 10 * 10;
	}

	~CAguila() {}

	void mover(Graphics^ g)
	{
		if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
		if (dx > 0) {
			idy = 3;
		}
		else {
			idy = 2;
		}
		x += dx;
		idx++;
		if (idx > 3)idx = 0;
	}
};
