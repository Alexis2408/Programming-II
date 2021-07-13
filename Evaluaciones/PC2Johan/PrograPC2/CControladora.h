#pragma once
#include "CCaballo.h"
#include "CAguila.h"
#include <vector>

using namespace std;

class CControladora {
private:
	CCaballo* caballo;
	CAguila* aguila;
	int cont;

public:
	CControladora(Bitmap^ bmpCaballo, Bitmap^ bmpAguila)
	{
		caballo = new CCaballo(bmpCaballo->Width / 6, bmpCaballo->Height / 8);
		aguila = new CAguila(bmpAguila->Width / 5, bmpAguila->Height / 4);
		cont = 0;
	}

	~CControladora() {}

	void moverTodos(Graphics^ g)
	{
		caballo->mover(g);
		aguila->mover(g);
	}

	void run(Graphics^ g, Bitmap^ bmpCaballo, Bitmap^ bmpAguila)
	{
		moverTodos(g);
		caballo->dibujar(g, bmpCaballo);
		invocarAguila(g, bmpAguila);
	}
	void invocarAguila(Graphics^ g, Bitmap^ bmpAguila)
	{
		aguila->dibujar(g, bmpAguila);
		cont++;
	}
	void setCaballloColor(char tecla)
	{
		switch (tecla)
		{
		case 'B':caballo->setColor(0);break;
		case 'V':caballo->setColor(1);break;
		case 'Z':caballo->setColor(3);break;
		case 'A':caballo->setColor(2);break;
		default:
			break;
		}
	}
	void aumentarVelocidadCaballo()
	{
		if (caballo->getDx() < 0)
			caballo->setDx(-20);
		if (caballo->getDx() > 0)
			caballo->setDx(20);

		if (caballo->getDy() < 0)
			caballo->setDy(-20);
		if (caballo->getDy() > 0)
			caballo->setDy(20);
	}
	CCaballo* getCaballo() { return caballo; }
};
