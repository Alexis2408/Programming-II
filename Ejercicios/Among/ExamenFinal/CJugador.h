#pragma once
#include "CMovil.h"
class CJugador
	: public CMovil
{
public:
	CJugador();
	CJugador(Bitmap^ bmp, int filas, int columnas);
	~CJugador();
	void mover(Graphics^ g, int direccion);
	int getVidas();
	void restarVidas();
private:
	int vidas;
};

CJugador::CJugador()
{
}

inline CJugador::CJugador(Bitmap^ bmp, int filas, int columnas) : CMovil(bmp, filas, columnas)
{
	y = 400;
	dx = 10;
	dy = 0;
	zoom = 0.3;
	vidas = 2;
}

CJugador::~CJugador()
{
}

inline void CJugador::mover(Graphics^ g, int direccion)
{
	direccion == 0 ? dx= 10 : dx = -10;
	if (x + dx < 0 || x + dx + ancho * zoom > g->VisibleClipBounds.Width) dx = 0;
	x += dx;
}

inline int CJugador::getVidas()
{
	return vidas;
}

inline void CJugador::restarVidas()
{
	this->vidas = vidas - 1;
}
