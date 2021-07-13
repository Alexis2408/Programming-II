#pragma once
#include "CRaton.h"
#include "CGato.h"
#include <ctime>
class CJuego
{
private:
	vector<CMovil*>ratones;
	CGato* gato;
	time_t inicio;
	time_t cron;
	int inicial;
	float activo;
public:
	CJuego();
	~CJuego();
	void jugar(int MAXW, int MAXH);
};

CJuego::CJuego()
{
	activo = 0;
	gato = new CGato();
	inicial = rand() % 7 + 6;
	for (int i = 0; i < inicial; i++)
	{
		CRaton* nuevo = new CRaton();
		ratones.push_back(nuevo);
	}
	cron = clock();
}

CJuego::~CJuego()
{
}

void CJuego::jugar(int MAXW, int MAXH)
{
	while (true)
	{
		for (int i = 0; i < ratones.size(); i++)
		{
			if (ratones.at(i)->movlento(activo))
			{
				ratones.at(i)->mover(MAXW, MAXH);
			}
			if (gato->colision(ratones.at(i)->getArea()))
			{
				ratones.at(i)->borrar();
				delete ratones.at(i);
				ratones.erase(ratones.begin() + i);
				i--;
				gato->mostrar();
			}
		}
		if (ratones.size() <= inicial / 2) { return; }
		if (kbhit())
		{
			switch (toupper(getch()))
			{								 
			case 'W':gato->setDx(0); gato->setDy(-1); break;
			case 'A':gato->setDx(-1); gato->setDy(0); break;
			case 'S':gato->setDx(0); gato->setDy(1); break;
			case 'D':gato->setDx(1); gato->setDy(0); break;
			case 'P':gato->setDx(0); gato->setDy(0); if (activo == 0) {
				activo = 9; inicio = clock();
			} break;
			case 'I':gato->setDx(0); gato->setDy(0); if (activo == 0) {
				activo = -0.9; inicio = clock();
			} break;
			default:gato->setDx(0); gato->setDy(0); break;
			}
			gato->mover(MAXW, MAXH);
		}
		if (activo != 0 && ((clock() - inicio) / CLOCKS_PER_SEC) >= 3)
		{
			activo = 0;
		}
		Console::SetCursorPosition(0, 0);
		cout << "tiempo: " << ((clock() - cron) / CLOCKS_PER_SEC);
		if (((clock()-cron)/CLOCKS_PER_SEC)>=60)
		{
			return;
		}
	}
}
