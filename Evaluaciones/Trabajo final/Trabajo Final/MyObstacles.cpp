#include "MyObstacles.h"

MyObstacles::MyObstacles(int x, int y, int width, int heigth)
{
	this->x = x;
	this -> y = y;
	this->width = width;
	this->heigth = heigth;
}

MyObstacles::~MyObstacles()
{
}

void MyObstacles::mostrar(Graphics^ g)
{
	Pen^ p = gcnew Pen(Color::Red, 5);
	g->DrawRectangle(p,x, y, width, heigth);
}

Rectangle MyObstacles::getRectangle()
{
	return Rectangle(x,y,width,heigth);
}
