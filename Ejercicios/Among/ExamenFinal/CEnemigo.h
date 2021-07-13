#pragma once
#include "CMovil.h"
#include "CJugador.h"
class CEnemigo
	:public CMovil
{
public:
	CEnemigo();
	CEnemigo(Bitmap^ bmp, int filas, int columnas);
	void mover(Graphics^ g);
	void atacar(Graphics^ g, CJugador* jug);
	~CEnemigo();
	bool getChute();
	void setChute(bool chute);
	int getVidas();
	void restarVidas();

private:
	int tipo;
	int vidas;
	bool chute;
};

CEnemigo::CEnemigo()
{
}

inline CEnemigo::CEnemigo(Bitmap^ bmp, int filas, int columnas) : CMovil(bmp, filas, columnas)
{
	x = rand() % 800;
	y = 2;
	dx = 10;
	dy = 0;
	vidas = 2;
	zoom = 0.7;
	chute = false;
}

inline void CEnemigo::mover(Graphics^ g)
{
	if (x + dx < 0 || x + dx + ancho * zoom > g->VisibleClipBounds.Width) dx *= -1;
	x += dx;
	if (idy > 3) idy = 0;
	idy++;
}

inline void CEnemigo::atacar(Graphics^ g, CJugador* jug)
{
	if (jug->getRec().Y - y - ancho*zoom > 200) {
		x + ancho*zoom / 2 < jug->getRec().X + jug->getRec().Width / 2 ? dx = 10 : dx = -10;
		y + alto*zoom + 30 / 2 < g->VisibleClipBounds.Bottom / 2 ? dy = 10 : dy = -10;
	}
	else
	{
		dx = 0; dy = 20;
	}
	x += dx;
	y += dy;
}

CEnemigo::~CEnemigo()
{
}
inline bool CEnemigo::getChute()
{
	return chute;
}
inline void CEnemigo::setChute(bool chute)
{
	this->chute = chute;
}
inline int CEnemigo::getVidas()
{
	return vidas;
}

inline void CEnemigo::restarVidas()
{
	this->vidas = vidas - 1;
}