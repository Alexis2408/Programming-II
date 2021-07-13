#pragma once
#include <iostream>
using namespace System::Drawing;
class CMovil
{
public:
	CMovil();
	CMovil(Bitmap^ bmp, int filas, int columnas);
	~CMovil();
	virtual void dibujar(Graphics^ g, Bitmap^ bmp);
	virtual void mover(Graphics^ g);
	bool colision(Rectangle rec);
	Rectangle getRec();
	Rectangle getFutRec();
	void setDy(int dy);
	void setZoom(float zoom);
	float getZoom();

protected:
	int x, y, dx, dy, ancho, alto;
	int idx, idy, filas, columnas;
	bool borrar;
	float zoom;
};

CMovil::CMovil()
{
}

inline CMovil::CMovil(Bitmap^ bmp, int filas, int columnas)
{
	zoom = 1.0;
	ancho = bmp->Width / columnas;
	alto = bmp->Height / filas;
	x = rand() % 300;
	y = rand() % 100;
	idx = idy = dx = dy = 0;
}

CMovil::~CMovil()
{
}

inline void CMovil::dibujar(Graphics^ g, Bitmap^ bmp)
{
	Rectangle seccion = Rectangle(ancho * idx, alto * idy, ancho, alto);
	g->DrawImage(bmp, getRec(), seccion, GraphicsUnit::Pixel);
}

inline void CMovil::mover(Graphics^ g)
{
}

inline bool CMovil::colision(Rectangle rec)
{
	return getRec().IntersectsWith(rec);
}

inline Rectangle CMovil::getRec()
{
	return Rectangle(x, y, ancho * zoom, alto * zoom);
}

inline Rectangle CMovil::getFutRec()
{
	return Rectangle(x + dx, y + dy, ancho * zoom, alto * zoom);
}

inline void CMovil::setDy(int dy)
{
	this->dy = dy;
}

inline void CMovil::setZoom(float zoom)
{
	this->zoom = zoom;
}

inline float CMovil::getZoom()
{
	return zoom;
}
