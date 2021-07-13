#pragma once
#include "CMovil.h"
class CCasa
	:public CMovil
{
private:
public:
	CCasa();
	~CCasa();
};

CCasa::CCasa() : CMovil()
{
	x = 88; y = 35;
	larga = 2;
	dibujo.push_back("  ___I_    ");
	dibujo.push_back(" /\\-_--\\ ");
	dibujo.push_back("/  \\_-__\\");
	dibujo.push_back("|[]| [] |  ");
}

CCasa::~CCasa()
{
}
