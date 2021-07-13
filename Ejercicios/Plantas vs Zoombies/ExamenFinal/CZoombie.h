#pragma once
#include "CMovil.h"
class CZoombie
	:public CMovil
{
public:
	CZoombie();
	CZoombie(Graphics^ g, Bitmap^ bmp, int filas, int columnas, int tipo);
	~CZoombie();
	void mover(Graphics^ g);
	void restarVidas();
	int getVidas();

private:
	int tipo;
	int vidas;
};

CZoombie::CZoombie()
{
}

inline CZoombie::CZoombie(Graphics^ g, Bitmap^ bmp, int filas, int columnas, int tipo) : CMovil(bmp, filas, columnas)
{
	dx = -5; dy = 0;
	this->tipo = tipo;
	vidas = 4;
	zoom = 0.15;
	int zy = g->VisibleClipBounds.Height - alto*zoom;
	x = g->VisibleClipBounds.Width - ancho*zoom - 10;
	y = rand() % zy;
}

CZoombie::~CZoombie()
{
}

inline void CZoombie::mover(Graphics^ g)
{
	x += dx;
}

inline void CZoombie::restarVidas()
{
	vidas--;
}

inline int CZoombie::getVidas()
{
	return vidas;
}
