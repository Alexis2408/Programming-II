#pragma once
#include <vector>
#include "CPlanta.h"
#include "CBala.h"
#include "CZoombie.h"
#include "CPlanta.h"
#include "CBloque.h"
using namespace std;
class CControladora
{
public:
	CControladora();
	CControladora(int vidas, int nPlantas, Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas,
		Bitmap^ bmpMapa, Bitmap^ bmpBloque);
	~CControladora();
	void run(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque, Bitmap^ bmpFicha);
	void dibujarTodos(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas,
		Bitmap^ bmpMapa, Bitmap^ bmpBloque, Bitmap^ bmpFicha);
	void moverTodos(Graphics^ g);
	void disparar(Bitmap^ bmpBalas);
	void colisiones(Graphics^g);
	CZoombie* getZoombie();
	bool getGano();

private:
	CZoombie* zoombie;
	vector<CBloque*> fichas;
	vector<CPlanta*> plantas;
	vector<CBala*> balas;
	vector<CBloque*> bloques;
	bool puedeDisparar;
	bool gano;
};

CControladora::CControladora()
{
}

inline CControladora::CControladora(int vidas, int nPlantas, Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies,
	Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque)
{
	zoombie = new CZoombie(bmpZoombies, 8, 12);
	zoombie->setVidas(vidas);
	for (int i = 0; i < nPlantas; i++)
	{
		plantas.push_back(new CPlanta(g, bmpPlantas, 1, 8));
	}
	for (int i = 0; i < 5; i++)
	{
		bloques.push_back(new CBloque(g, bmpBloque, 1, 1));
	}
	puedeDisparar = gano = false;
}

CControladora::~CControladora()
{
}

inline void CControladora::run(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas,
	Bitmap^ bmpMapa, Bitmap^ bmpBloque, Bitmap^ bmpFicha)
{
	if (zoombie->getRec().Y < 0)
	{
		gano = true;
	}
	if (!gano)
	{
		if (rand() % 23 == 3)
		{
			fichas.push_back(new CBloque(g, bmpFicha, 1, 1, 0.02));
		}
		zoombie->dibujar(g, bmpZoombies);
		colisiones(g);
		moverTodos(g); 
		dibujarTodos(g, bmpPlantas, bmpZoombies, bmpBalas, bmpMapa, bmpBloque, bmpFicha);
	}
	
}

inline void CControladora::dibujarTodos(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas,
	Bitmap^ bmpMapa, Bitmap^ bmpBloque, Bitmap^ bmpFicha)
{
	for (int i = 0; i < plantas.size(); i++)
		plantas.at(i)->dibujar(g, bmpPlantas);
	for (int i = 0; i < balas.size(); i++)
		balas.at(i)->dibujar(g, bmpBalas);
	for (int i = 0; i < bloques.size(); i++)
		bloques.at(i)->dibujar(g, bmpBloque);
	for (int i = 0; i < fichas.size(); i++)
		fichas.at(i)->dibujar(g, bmpFicha);
}

inline void CControladora::moverTodos(Graphics^ g)
{
	for (int i = 0; i < plantas.size(); i++)
		plantas.at(i)->mover(g);
	for (int i = 0; i < balas.size(); i++)
		balas.at(i)->mover(g);
}

inline void CControladora::disparar(Bitmap^ bmpBalas)
{
	if (puedeDisparar)
	{
		balas.push_back(new CBala(bmpBalas, 1, 1, zoombie));
		puedeDisparar = false;
	}
	
}

inline void CControladora::colisiones(Graphics^ g)
{
	//colision zoombies plantas
	for (int i = 0; i < plantas.size(); i++)
	{
		if (plantas.at(i)->colision(zoombie->getRec()))
		{
			zoombie->restarVidas();
			zoombie->posicionInicial();
			plantas.erase(plantas.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < bloques.size(); i++)
	{
		if (bloques.at(i)->colision(zoombie->getFutRec()))
		{
			zoombie->setNoMover(true);
		}
		else
		{
			zoombie->setNoMover(false);
		}
	}
	//colision balas plantas
	for (int i = 0; i < balas.size(); i++)
	{
		for (int j = 0; j < plantas.size(); j++)
		{
			if (balas.at(i)->colision(plantas.at(j)->getRec()))
			{
				plantas.erase(plantas.begin() + j);
				balas.erase(balas.begin() + i);
				i--;
				break;
			}
		}
	}
	//colision zoombies fichas
	for (int i = 0; i < fichas.size(); i++)
	{
		if (fichas.at(i)->colision(zoombie->getRec()))
		{
			puedeDisparar = true;
			fichas.erase(fichas.begin() + i);
		}
	}
	//balas perdidas
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->getRec().X > g->VisibleClipBounds.Right || balas.at(i)->getRec().X < 0 ||
			balas.at(i)->getRec().Y > g->VisibleClipBounds.Bottom || balas.at(i)->getRec().Y < 0)
		{
			balas.erase(balas.begin() + i);
			i--;
		}
	}
	//L plantas
	for (int i = 0; i < plantas.size(); i++)
	{
		if (plantas.at(i)->getVidas() == 0)
		{
			plantas.erase(plantas.begin() + i);
			i--;
		}
	}
}

inline CZoombie* CControladora::getZoombie()
{
	return zoombie;
}

inline bool CControladora::getGano()
{
	return gano;
}
