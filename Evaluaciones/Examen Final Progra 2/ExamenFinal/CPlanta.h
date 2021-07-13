#pragma once
#include "CMovil.h"
class CPlanta
	:public CMovil
{
public:
	CPlanta();
	CPlanta(Graphics^ g, Bitmap^ bmp, int filas, int columnas);
	~CPlanta();
	void mover(Graphics^ g);
	void restarVidas();
	int getVidas();

private:
	int tipo;
	int vidas;
};

CPlanta::CPlanta()
{
}

inline CPlanta::CPlanta(Graphics^ g, Bitmap^ bmp, int filas, int columnas) : CMovil(bmp, filas, columnas)
{
	int rx = g->VisibleClipBounds.Width - 50;
	int ry = g->VisibleClipBounds.Height - 50;
	x = rand() % rx;
	y = rand() % ry;
	do
	{
		dx = (rand() % 3 - 1) * 10;
		dy = (rand() % 3 - 1) * 10;
	} while (dx == 0 && dy == 0);
	vidas = 3;
	zoom = 1.2;
	tipo = rand() % 8;
	idx = tipo;
}

CPlanta::~CPlanta()
{
}

inline void CPlanta::mover(Graphics^ g)
{
	if (x + dx < 0 || x + dx + ancho * zoom > g->VisibleClipBounds.Width) dx *=-1;
	if (y + dy < 0 || y + dy + alto * zoom > g->VisibleClipBounds.Height) dy *=-1;
	x += dx;
	y += dy;
}

inline void CPlanta::restarVidas()
{
	vidas--;
}

inline int CPlanta::getVidas()
{
	return vidas;
}
