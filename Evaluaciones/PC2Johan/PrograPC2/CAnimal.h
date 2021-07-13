#pragma once
#include <iostream>

using namespace System::Drawing;

class CAnimal {
protected:
	int x, y, dx, dy, ancho, alto, idx, idy;

public:
	CAnimal(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
	}

	~CAnimal() {}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void mover(Graphics^ g) {}

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	
};
