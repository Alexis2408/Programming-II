#pragma once
#include "CMovil.h"
class CRaton
	:public CMovil
{
private:
public:
	CRaton();
	~CRaton();
	void movinvalido(int x)
	{
		if (x == 1) { dx *= -1; }
		if (x == 2) { dy *= -1; }
	}
};

CRaton::CRaton(): CMovil()
{
	larga = 0;
	dibujo.push_back("--(_c'>");
	do
	{
		dx = rand() % 3 - 1;
		dy = rand() % 3 - 1;
	} while (dx ==0 && dy == 0);
}

CRaton::~CRaton()
{
	dibujo.clear();
}
