#pragma once
#include "CMovil.h"
#include <conio.h>
class CMonigote :
    public CMovil
{
private:
	int pasos;
	int vidas;
public:
    CMonigote();
    ~CMonigote();
	void movinvalido(int x);
	//atributos especiales y propios del monigote
	int getVidas();
	int getPasos();
	void setVidas(int vidas);
	void setPasos(int pasos);

};

CMonigote::CMonigote() :CMovil()
{
	pasos = larga = 0;
	x = 3; y = 2;
	vidas = 3;
	char caracter = (char)197;
	string cadena = { caracter };
	dibujo.push_back("0");
	dibujo.push_back(cadena);
}

CMonigote::~CMonigote()
{
}

void CMonigote::movinvalido(int x)
{
	dx = dy = 0;
}

int CMonigote::getVidas()
{
	return vidas;
}

int CMonigote::getPasos()
{
	return pasos;
}

void CMonigote::setVidas(int vidas)
{
	this->vidas = vidas;
}

void CMonigote::setPasos(int pasos)
{
	this->pasos = pasos;
}
