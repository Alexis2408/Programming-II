#pragma once
#include "CMovil.h"
#include "CJugador.h"
class CBala
	: public CMovil
{
public:
	CBala();
	CBala(Bitmap^ bmp, int filas, int columnas, CMovil* mov);
	CBala(CJugador* jug);
	~CBala();
	void mover(Graphics^ g);

private:

};

CBala::CBala()
{
}

inline CBala::CBala(Bitmap^ bmp, int filas, int columnas, CMovil* mov) : CMovil (bmp, filas, columnas)
{
	x = mov->getRec().X + mov->getRec().Width * mov->getZoom() / 2 + bmp->Width * this->zoom / 2;
	y = mov->getRec().Y + mov->getRec().Height * mov->getZoom() / 2 + bmp->Height * this->zoom / 2;
	dx = 0;
	dy = -35;
}

inline CBala::CBala(CJugador* jug)
{
	x = jug->getRec().X;
	y = jug->getRec().Y;
	dx = 0;
	dy = 15;
}

CBala::~CBala()
{
}

inline void CBala::mover(Graphics^ g)
{
	/*if (y + dy < 0 || y + dy + alto*zoom > g->VisibleClipBounds.Width) dy = 0;*/
	y += dy;
}
