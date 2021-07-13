#pragma once
#include "CCasa.h"
#include "CMonigote.h"
#include "CVacuna.h"
#include "CVirus.h"
class CControladora
{
private:
	CCasa* casa;
	CMonigote* monigote;
	vector<CVacuna*> vacunas;
	vector<CVirus*> vecVirus;
	bool inmunidad;
	int pasosIniciales;
	int inicial;
	float activo;

public:
	CControladora();
	~CControladora();
	void prepararJuego();
	void empezar(int MAXW, int MAXH);
	void resumen(int fin);
};

CControladora::CControladora()
{
	prepararJuego();
}

CControladora::~CControladora()
{
}

void CControladora::prepararJuego() // Prepara los elementos del juego
{
	casa = new CCasa();
	monigote = new CMonigote();
	inmunidad = false;
	pasosIniciales = 0;
	activo = 0;
	inicial = rand() % 7 + 6;
	for (int i = 0; i < 5; i++)
	{
		vacunas.push_back(new CVacuna);
	}
	for (int i = 0; i < rand()%5+4; i++)
	{
		vecVirus.push_back(new CVirus);
	}

}

void CControladora::empezar(int MAXW, int MAXH)
{
	while (true)
	{
		casa->mostrar();
		monigote->mostrar();
		//se muestran en pantalla los datos
		Console::SetCursorPosition(70, 0);
		cout << "Pasos: " << monigote->getPasos();
		if (inmunidad == false)
		{
			Console::SetCursorPosition(70, 1);
			cout << "Quedan  0 inmunes";
		}
		Console::SetCursorPosition(70, 3);
		cout << "Numero de virus moviendose: " << vecVirus.size();
		Console::SetCursorPosition(70, 2);
		cout << "Impacto por virus: " << 3 - monigote->getVidas();
		for (int i = 0; i < vecVirus.size(); i++) // verifica los colisiones de los virus
		{
			if (vecVirus.at(i)->movlento(activo))
			{
				vecVirus.at(i)->mover(MAXW, MAXH);
			}
			if (inmunidad == true) 
			{
				Console::SetCursorPosition(70, 1);
				cout << "Quedan " << abs(10 - (monigote->getPasos() - pasosIniciales)) << " inmunes";
				if (monigote->getPasos() - pasosIniciales == 10)
					inmunidad = false;
			}
			else
			{
				if (monigote->colision(vecVirus.at(i)->getArea()))
				{
					monigote->setVidas(monigote->getVidas() - 1);
					monigote->borrar();
					monigote->setX(3);
					monigote->setY(2);
					monigote->mostrar();
				}
			}
			
		}
		for (int i = 0; i < vacunas.size(); i++) // verifica las colisiones de las vacunas
		{
			if (vacunas.at(i)->movlento(7))
			{
				vacunas.at(i)->mover(MAXW, MAXH);
			}
			if (monigote->colision(vacunas.at(i)->getArea()))
			{
				inmunidad = true;
				pasosIniciales = monigote->getPasos();
				vacunas.at(i)->borrar();
				delete vacunas.at(i);
				vacunas.erase(vacunas.begin() + i);
				i--;
				monigote->mostrar();
			}
		}
		if (kbhit()) // se encarga del movimiento del monigote
		{
			switch (toupper(getch()))
			{
			case 72:monigote->setDx(0); monigote->setDy(-1);
				monigote->setPasos(monigote->getPasos() + 1); break;
			case 75:monigote->setDx(-1); monigote->setDy(0);
				monigote->setPasos(monigote->getPasos() + 1); break;
			case 80:monigote->setDx(0); monigote->setDy(1);
				monigote->setPasos(monigote->getPasos() + 1); break;
			case 77:monigote->setDx(1); monigote->setDy(0);
				monigote->setPasos(monigote->getPasos() + 1); break;
			default:monigote->setDx(0); monigote->setDy(0); break;
			}
			monigote->mover(MAXW, MAXH);
		}
		
		if (monigote->getVidas() <= 0)
		{
			resumen(1);
			return;
		}
		if (monigote->colision(casa->getArea()))
		{
			resumen(0);
			return;
		}
	}

}

void CControladora::resumen(int fin)
{
	Console::Clear();
	Console::SetCursorPosition(20, 20);
	if (fin == 0)//en un caso positivo muestra el ganar
	{
		
		cout << "Ganaste brother";
	}
	else//caso contrario muestra el perder
	{
		cout << "Perdiste brother";
	}
	Console::SetCursorPosition(20, 22);
	cout << "Tus pasos fueron: " << monigote->getPasos();
	_getch();
}
