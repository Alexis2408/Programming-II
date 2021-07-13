#pragma once
#include "CMovil.h"
class CZoombie
	: public CMovil
{
public:
	CZoombie();
	CZoombie(Bitmap^ bmp, int filas, int columnas);
	~CZoombie();
	void mover(Graphics^ g, char direccion);
	void posicionInicial();
	int getVidas();
	void setVidas(int vidas);
	void restarVidas();
	void setNoMover(bool noMover);
private:
	int vidas;
	int power;
	bool noMover;
};

CZoombie::CZoombie()
{
}

inline CZoombie::CZoombie(Bitmap^ bmp, int filas, int columnas) : CMovil(bmp, filas, columnas)
{
	y = 400;
	x = 300;
	dx = 10;
	dy = 10;
	zoom = 0.8;
	vidas = 2;
	noMover = false;
}

CZoombie::~CZoombie()
{
}

inline void CZoombie::mover(Graphics^ g, char direccion)
{
	if (!noMover)
	{
		switch (direccion)
		{
		case 'W': dx = 0; dy = -10; idy = 0; break;
		case 'A': dx = -10; dy = 0; idy = 3; break;
		case 'S': dx = 0; dy = 10; idy = 2; break;
		case 'D': dx = 10; dy = 0; idy = 1; break;
		case 'E': dx = 0; dy = 0; break;
		}
		if (x + dx < 0 || x + dx + ancho * zoom > g->VisibleClipBounds.Width) dx = 0;
		if (y + dy + alto * zoom > g->VisibleClipBounds.Height) dy = 0;
		x += dx;
		y += dy;
		idx++;
		if (idx > 2) idx = 0;
	}
}

inline void CZoombie::posicionInicial()
{
	x = 300;
	y = 400;
}

inline int CZoombie::getVidas()
{
	return vidas;
}

inline void CZoombie::setVidas(int vidas)
{
	this->vidas = vidas;
}

inline void CZoombie::restarVidas()
{
	this->vidas = vidas - 1;
}

inline void CZoombie::setNoMover(bool noMover)
{
	this->noMover = noMover;
}
