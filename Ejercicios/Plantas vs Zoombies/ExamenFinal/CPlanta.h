#pragma once
#include "CMovil.h"
class CPlanta
	:public CMovil
{
public:
	CPlanta();
	CPlanta(int x, int y, Bitmap^ bmp, int filas, int columnas);
	~CPlanta();
	void restarVidas();
	int getVidas();

private:
	int tipo;
	int vidas;
};

CPlanta::CPlanta()
{
}

inline CPlanta::CPlanta(int x, int y, Bitmap^ bmp, int filas, int columnas) : CMovil(bmp, filas, columnas)
{
	this->x = x;
	this->y = y;
	dx = dy = 0;
	vidas = 3;
	zoom = 0.23;
}

CPlanta::~CPlanta()
{
}

inline void CPlanta::restarVidas()
{
	vidas--;
}

inline int CPlanta::getVidas()
{
	return vidas;
}
