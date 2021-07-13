#pragma once
#include "CMovil.h"
class CBala
	: public CMovil
{
public:
	CBala();
	CBala(Bitmap^ bmp, int filas, int columnas, CMovil* mov);
	CBala(Bitmap^ bmp, int x, int y, int filas, int columnas);
	~CBala();
	void mover(Graphics^ g);

private:

};

CBala::CBala()
{
}

inline CBala::CBala(Bitmap^ bmp, int filas, int columnas, CMovil* mov) : CMovil(bmp, filas, columnas)
{
	x = mov->getRec().X + mov->getRec().Width * mov->getZoom() / 2 + bmp->Width * this->zoom / 2;
	y = mov->getRec().Y + mov->getRec().Height * mov->getZoom() / 2 + bmp->Height * this->zoom / 2;
	dx = 25;
	dy = 0;
	zoom = 0.08;
}

inline CBala::CBala(Bitmap^ bmp,int x, int y, int filas = 1, int columnas = 1) : CMovil(bmp, filas, columnas)
{
	this->x = x;
	this->y = y;
	dx = 25; dy = 0;
	zoom = 0.08;
}

CBala::~CBala()
{
}

inline void CBala::mover(Graphics^ g)
{
	x += dx;
}
