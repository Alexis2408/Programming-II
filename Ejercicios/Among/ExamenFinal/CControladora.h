#pragma once
#include <vector>
#include "CPersonaje.h"
using namespace std;
class CControladora
{
public:
	CControladora();
	CControladora(Bitmap^ bmpPersonaje);
	~CControladora();
	void run(Graphics^ g, Bitmap^ bmpPersonaje);
	void colisiones(Graphics^g);
	bool setAparicion(bool aparicion);

private:
	vector<CPersonaje*> personajes;
	bool aparicion;
};

CControladora::CControladora()
{
}

inline CControladora::CControladora(Bitmap^ bmpPersonaje)
{
	personajes.push_back(new CPersonaje(bmpPersonaje));
	personajes.push_back(new CPersonaje(bmpPersonaje));
	aparicion = false;
}

CControladora::~CControladora()
{
}

inline void CControladora::run(Graphics^ g, Bitmap^ bmpPersonaje)
{
	if (aparicion && personajes.size() <= 6)
	{
		personajes.push_back(new CPersonaje(bmpPersonaje));
		aparicion = false;
	}
	for (int i = 0; i < personajes.size(); i++)
	{
		personajes.at(i)->mover(g);
	}
	colisiones(g);
	for (int i = 0; i < personajes.size(); i++)
	{
		personajes.at(i)->dibujar(g, bmpPersonaje);
	}

}


inline void CControladora::colisiones(Graphics^ g)
{
	for (int i = 0; i < personajes.size()-1; i++)
	{
		for (int j = i+1; j < personajes.size(); j++)
		{
			if (personajes.at(i)->colision(personajes.at(j)->getRec()) && personajes.at(i)->getConquistado()==false &&
				personajes.at(j)->getConquistado() == false)
			{
				int a = rand() % 2;
				if (a % 2)
				{
					personajes.at(j)->setConquistado(true);
					personajes.at(j)->setColor(personajes.at(i)->getColor());
					personajes.at(i)->setZoom(personajes.at(i)->getZoom() + 0.3);
					personajes.at(i)->aumentarNConquistas();
				}
				else
				{
					personajes.at(i)->setConquistado(true);
					personajes.at(i)->setColor(personajes.at(j)->getColor());
					personajes.at(j)->setZoom(personajes.at(i)->getZoom() + 0.3);
					personajes.at(j)->aumentarNConquistas();
				}
			}
			/*break;*/
		}
	}
}

inline bool CControladora::setAparicion(bool aparicion)
{
	return this->aparicion = aparicion;
}
