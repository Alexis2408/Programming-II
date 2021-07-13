#pragma once
#include "CMovil.h"
class CGato
	:public CMovil
{
private:
public:
	CGato();
	~CGato();
	void movinvalido(int x)
	{
		dx = dy = 0;
	}
};

CGato::CGato(): CMovil()
{
	larga = 1;
	dibujo.push_back(" /\\_/\\");
	dibujo.push_back("( o.o )");
	dibujo.push_back(" > ^ <");
}

CGato::~CGato()
{
	dibujo.clear();
}