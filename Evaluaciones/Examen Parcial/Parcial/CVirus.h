#pragma once
#include "CMovil.h"
class CVirus
	:public CMovil
{
private:
public:
	CVirus();
	~CVirus();
	void movinvalido(int x);

};

CVirus::CVirus(): CMovil()
{
	larga = 2;
	x = rand() % 80 + 10;
	y = rand() % 20 + 10;
	do
	{
		dx = rand() % 3 - 1;
		dy = rand() % 3 - 1;
	} while (dx ==0 && dy == 0);
	dibujo.push_back("     q      ");
	dibujo.push_back("  o.-o-.o   ");
	dibujo.push_back("o-(o o o) -o");
	dibujo.push_back("  o._o_.o   ");
	dibujo.push_back("     b      ");
}

CVirus::~CVirus()
{
}

void CVirus::movinvalido(int x)
{
	if (x == 1) { dx *= -1; }
	if (x == 2) { dy *= -1; }
}
