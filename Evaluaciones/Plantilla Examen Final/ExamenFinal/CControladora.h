#pragma once
#include <vector>
#include "CJugador.h"
#include "CBala.h"
#include "CEnemigo.h"
using namespace std;
class CControladora
{
public:
	CControladora();
	CControladora(Bitmap^ bmpJugador, Bitmap^ bmpEnemigos, Bitmap^ bmpMapa);
	~CControladora();
	void run(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigos, Bitmap^ bmpMapa, Bitmap^ bmpBala);
	void disparar(Bitmap^ bmpBala);
	void dispararEnemigos(Bitmap^ bmpBala);
	void colisiones(Graphics^g);
	CJugador* getJugador();

private:
	CJugador* jug;
	vector<CBala*> balas;
	vector<CBala*>balasene;
	vector<CEnemigo*> enemigos;
};

CControladora::CControladora()
{
}

inline CControladora::CControladora(Bitmap^ bmpJugador, Bitmap^ bmpEnemigos, Bitmap^ bmpMapa)
{
	jug = new CJugador(bmpJugador, 1, 1);
	for (int i = 0; i < 6; i++)
	{
		enemigos.push_back(new CEnemigo(bmpEnemigos, 5, 3));
	}
}

CControladora::~CControladora()
{
}

inline void CControladora::run(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigos, Bitmap^ bmpMapa, Bitmap^ bmpBala)
{
	jug->dibujar(g, bmpJugador);
	for (int i = 0; i < balas.size(); i++)
	{
		balas.at(i)->dibujar(g, bmpBala);
		balas.at(i)->mover(g);
	}
	for (int i = 0; i < balasene.size(); i++)
	{
		balasene.at(i)->dibujar(g, bmpBala);
		balasene.at(i)->mover(g);
	}
	if (enemigos.size() > 0)
	{
		if (rand() % 20 == 3)
		{
			int i = rand() % enemigos.size();
			enemigos.at(i)->setChute(true);

		}
	}
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (enemigos.size() > 0)
		{
			if (enemigos.at(i)->getChute())
			{
				enemigos.at(i)->atacar(g, jug);
			}
			else
			{
				if (rand() % 20 == 3)
				{
					dispararEnemigos(bmpBala);
				}
				enemigos.at(i)->mover(g);
			}
			enemigos.at(i)->dibujar(g, bmpEnemigos);
		}
	}
	colisiones(g);
}

inline void CControladora::disparar(Bitmap^ bmpBala)
{
	balas.push_back(new CBala(bmpBala, 1, 1, jug));
}

inline void CControladora::dispararEnemigos(Bitmap^ bmpBala)
{
	if (enemigos.size() > 0) 
	{
		int i = rand() % enemigos.size();
		CBala* nueva = new CBala(bmpBala, 1, 1, enemigos.at(i));
		nueva->setDy(20);
		balasene.push_back(nueva);
	}
}

inline void CControladora::colisiones(Graphics^ g)
{
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (enemigos.at(i)->colision(jug->getRec()))
		{
			enemigos.erase(enemigos.begin() + i);
			jug->restarVidas();
			i--;
		}
	}
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->getRec().Y < g->VisibleClipBounds.Top)
		{
			balas.erase(balas.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < balas.size(); i++)
	{
		for (int j = 0; j < enemigos.size(); j++)
		{
			if (balas.at(i)->colision(enemigos.at(j)->getRec()))
			{
				enemigos.at(j)->restarVidas();
				balas.erase(balas.begin() + i);
				/*enemigos.erase(enemigos.begin() + j);
				j--;*/
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (enemigos.at(i)->getRec().Y>g->VisibleClipBounds.Bottom)
		{
			enemigos.erase(enemigos.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < enemigos.size(); i++)
	{
		if (enemigos.at(i)->getVidas() == 0)
		{
			enemigos.erase(enemigos.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < balasene.size(); i++)
	{
		if (balasene.at(i)->colision(jug->getRec()))
		{
			balasene.erase(balasene.begin() + i);
			jug->restarVidas();
			i--;
			break;
		}
	}
}

inline CJugador* CControladora::getJugador()
{
	return jug;
}
