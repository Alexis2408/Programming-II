#pragma once
#include "CMovil.h"
class CVacuna
	:public CMovil
{
private:
public:
	CVacuna();
	~CVacuna();
	void movinvalido(int x);
};

CVacuna::CVacuna(): CMovil()
{
	larga = 0;
	x = rand() % 80 + 10;
	y = rand() % 20 + 10;
	do
	{
		dx = rand() % 3 - 1;
		dy = rand() % 3 - 1;
	} while (dx == 0 && dy == 0 || (dx !=0 && dy !=0));
	dibujo.push_back("|--->|");
}

CVacuna::~CVacuna()
{
}
void CVacuna::movinvalido(int x)
{
	if (x == 1) { dx *= -1; }
	if (x == 2) { dy *= -1; }
}