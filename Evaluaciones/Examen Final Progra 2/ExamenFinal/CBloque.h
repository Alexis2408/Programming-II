#pragma once
#include "CMovil.h"
class CBloque
	:public CMovil
{
public:
	CBloque();
	CBloque(Graphics^ g, Bitmap^ bmp, int filas, int columnas, float zoom);
	~CBloque();

private:
};

CBloque::CBloque()
{
}

inline CBloque::CBloque(Graphics^ g, Bitmap^ bmp, int filas, int columnas, float zoom = 1.2) : CMovil(bmp, filas, columnas)
{
	int rx = g->VisibleClipBounds.Width - 50;
	int ry = g->VisibleClipBounds.Height - 50;
	x = rand() % rx;
	y = rand() % ry;
	dx = dy = 0;
	this->zoom = zoom;
}

CBloque::~CBloque()
{
}