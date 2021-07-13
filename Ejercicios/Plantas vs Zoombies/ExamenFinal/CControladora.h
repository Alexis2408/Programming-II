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
	CControladora(int nBloques, Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque);
	~CControladora();
	void run(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque);
	void dibujarTodos(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque);
	void moverTodos(Graphics^ g);
	void disparar(vector<CPlanta*> plantas, vector<CZoombie*> zoombies, Bitmap^ bmpBalas);
	void colisiones(Graphics^g);
	CPlanta* getJugador();

private:
	vector<CPlanta*> plantas;
	vector<CBala*> balas;
	vector<CZoombie*> zoombies;
	vector<CBloque*> bloques;
	int cont, cont1;
	int nBloques;
};

CControladora::CControladora()
{
}

inline CControladora::CControladora(int nBloques, Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque)
{
	for (int i = 0; i < 6; i++)
	{
		plantas.push_back(new CPlanta(0, i * 100, bmpPlantas, 1, 1));
	}
	cont = cont1 = 0;
	for (int i = 0; i < nBloques; i++)
	{
		bloques.push_back(new CBloque(g, bmpBloque, 1, 1));
	}
}

CControladora::~CControladora()
{
}

inline void CControladora::run(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque)
{
	cont++;
	if (cont == 35)
	{
		zoombies.push_back(new CZoombie(g, bmpZoombies, 1, 1, 4));
		cont = 0;
		cont1++;
	}
	if (cont1 == 1)
	{
		disparar(plantas, zoombies, bmpBalas);
		cont1 = 0;
	}
	moverTodos(g);
	disparar(plantas, zoombies, bmpBalas);
	dibujarTodos(g, bmpPlantas, bmpZoombies, bmpBalas, bmpMapa, bmpBloque);
	colisiones(g);
}

inline void CControladora::dibujarTodos(Graphics^ g, Bitmap^ bmpPlantas, Bitmap^ bmpZoombies, Bitmap^ bmpBalas, Bitmap^ bmpMapa, Bitmap^ bmpBloque)
{
	for (int i = 0; i < plantas.size(); i++)
		plantas.at(i)->dibujar(g, bmpPlantas);
	for (int i = 0; i < zoombies.size(); i++)
		zoombies.at(i)->dibujar(g, bmpZoombies);
	for (int i = 0; i < balas.size(); i++)
		balas.at(i)->dibujar(g, bmpBalas);
	for (int i = 0; i < bloques.size(); i++)
		bloques.at(i)->dibujar(g, bmpBloque);
}

inline void CControladora::moverTodos(Graphics^ g)
{
	for (int i = 0; i < plantas.size(); i++)
		plantas.at(i)->mover(g);
	for (int i = 0; i < zoombies.size(); i++)
		zoombies.at(i)->mover(g);
	for (int i = 0; i < balas.size(); i++)
		balas.at(i)->mover(g);
}

inline void CControladora::disparar(vector<CPlanta*> plantas, vector<CZoombie*> zoombies, Bitmap^ bmpBalas)
{
	if (rand() % 15== 4)
	{
		for (int i = 0; i < zoombies.size(); i++)
		{
			balas.push_back(new CBala(bmpBalas, 15, zoombies.at(i)->getRec().Y + zoombies.at(i)->getRec().Height / 2));
		}
	}
	
}

inline void CControladora::colisiones(Graphics^ g)
{
	//colision zoombies plantas
	for (int i = 0; i < zoombies.size(); i++)
	{
		for (int j = 0; j < plantas.size(); j++)
		{
			if (zoombies.at(i)->colision(plantas.at(j)->getRec()))
			{
				plantas.at(j)->restarVidas();
			}
		}
	}
	//colision zoombies bloques
	for (int i = 0; i < zoombies.size(); i++)
	{
		for (int j = 0; j < bloques.size(); j++)
		{
			if (zoombies.at(i)->colision(bloques.at(j)->getRec()))
			{
				bloques.erase(bloques.begin() + j);
				j--;
				zoombies.at(i)->setDx(5);
				break;
			}
		}
	}
	//colision balas zoombies
	for (int i = 0; i < balas.size(); i++)
	{
		for (int j = 0; j < zoombies.size(); j++)
		{
			if (balas.at(i)->colision(zoombies.at(j)->getRec()))
			{
				zoombies.at(j)->restarVidas();
				balas.erase(balas.begin() + i);
				i--;
				break;
			}
		}
	}
	//balas perdidas
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->getRec().X > g->VisibleClipBounds.Right)
		{
			balas.erase(balas.begin() + i);
			i--;
		}
	}
	//zoombies con el borde izquierdo
	for (int i = 0; i < zoombies.size(); i++)
	{
		if (zoombies.at(i)->getRec().Y>g->VisibleClipBounds.Right)
		{
			zoombies.erase(zoombies.begin() + i);
			i--;
		}
	}
	//L zoombies
	for (int i = 0; i < zoombies.size(); i++)
	{
		if (zoombies.at(i)->getVidas() <= 0 || zoombies.at(i)->getRec().X> 1045)
		{
			zoombies.erase(zoombies.begin() + i);
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

inline CPlanta* CControladora::getJugador()
{
	/*return jug;*/
}
