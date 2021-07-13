#pragma once
#include "CMovil.h"
class CPersonaje
	:public CMovil
{
public:
	CPersonaje();
	CPersonaje(Bitmap^ bmp, int filas, int columnas, int color);
	~CPersonaje();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover(Graphics^ g);
	void setColor(int color);
	int getColor();
	void aumentarNConquistas();
	void setConquistado(bool conquistado);
	int getNConquistas();
	bool getConquistado();

private:
	int color;
	int nconsquitas;
	bool conquistado;
};

CPersonaje::CPersonaje()
{
}

inline CPersonaje::CPersonaje(Bitmap^ bmp, int filas = 5, int columnas = 6, int color = rand() % 6) : CMovil(bmp, filas, columnas)
{
	this->color = color;
	x = rand() % 700;
	y = rand() % 350;
	do
	{
		dx = 10 * (rand() % 3 - 1);
		dy = 10 * (rand() % 3 - 1);
	} while (dx==0 && dy == 0);
	nconsquitas = 0;
	conquistado = false;
}

CPersonaje::~CPersonaje()
{
}

inline void CPersonaje::dibujar(Graphics^ g, Bitmap^ bmp)
{
	if (conquistado)
	{
		g->DrawString(String("c"), Font("Arial", 16), SolidBrush(Color::Red), x, y);
	}
	Rectangle seccion = Rectangle(ancho * color, alto * idy, ancho, alto);
	g->DrawImage(bmp, getRec(), seccion, GraphicsUnit::Pixel);
}

inline void CPersonaje::mover(Graphics^ g)
{
	if (x + dx < 0 || x + dx + ancho * zoom > g->VisibleClipBounds.Width) dx *= -1;
	if (y + dy < 0 || y + dy + alto * zoom > g->VisibleClipBounds.Height) dy *= -1;
	x += dx;
	y += dy;
	idy++;
	if (idy == 4) idy = 0;
}

inline void CPersonaje::setColor(int color)
{
	this->color = color;
}

inline int CPersonaje::getColor()
{
	return color;
}

inline void CPersonaje::aumentarNConquistas()
{
	nconsquitas++;
}

inline void CPersonaje::setConquistado(bool conquistado)
{
	this->conquistado = conquistado;
}

inline int CPersonaje::getNConquistas()
{
	return nconsquitas;
}

inline bool CPersonaje::getConquistado()
{
	return conquistado;
}
