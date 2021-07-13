#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace System;
using namespace System::Drawing;
using namespace std;

class CMovil
{
protected:
	//Atributos de la clase padre
	vector<string>dibujo;
	int x, y, dx, dy, larga, velocidad, aceleracion;

public:
	//Funciones de la clase padre
	CMovil();
	~CMovil();
	void setX(int x);
	void setY(int y);
	void setDx(int dx);
	void setDy(int dy);
	int getX();
	int getY();
	void borrar();
	virtual void mover(int MAXW, int MAXH);
	void mostrar();
	bool movlento(float hiper); //Esta funcion permite controlar la velocidad del movimiento
	virtual void movinvalido(int x){}
	Rectangle getArea();
	bool colision(Rectangle rec);
};

CMovil::CMovil()
{
	aceleracion = dx = dy = 0;
	velocidad = (rand() % 37 + 4) * 10;
}

CMovil::~CMovil()
{
}

void CMovil::setX(int x)
{ this->x = x; }

void CMovil::setY(int y)
{ this->y = y; }

void CMovil::setDx(int dx)
{ this->dx = dx; }

void CMovil::setDy(int dy)
{ this->dy = dy; }

int CMovil::getX()
{ return this->x; }

int CMovil::getY()
{ return this->y; }

bool CMovil::movlento(float hiper)
{
	if (aceleracion >= velocidad*(hiper+1))
	{
		aceleracion = 0;
		return true;
	}
	else
	{
		aceleracion++;
	}
	return false;
}
void CMovil::borrar()
{
	for (int i = 0; i < dibujo.size(); i++)
	{
		for (int j = 0; j < dibujo.at(i).length(); j++)
		{
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
	}
}

void CMovil::mover(int MAXW, int MAXH)
{
	borrar();
	if (x + dx < 0 || x + dx + dibujo.at(larga).length() > MAXW)
	{
		movinvalido(1);
	}
	if (y + dy < 0 || y + dy + dibujo.size() > MAXH)
	{
		movinvalido(2);
	}
	x += dx;
	y += dy;
	mostrar();
}

void CMovil::mostrar()
{
	for (int i = 0; i < dibujo.size(); i++)
	{
		Console::SetCursorPosition(x, y + i);
		cout << dibujo.at(i);
	}
}

Rectangle CMovil::getArea()
{ return Rectangle(x, y, dibujo.at(larga).length(), dibujo.size()); }

bool CMovil::colision(Rectangle rec)
{ return getArea().IntersectsWith(rec); }


