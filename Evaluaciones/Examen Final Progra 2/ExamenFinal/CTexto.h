#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace System;
using namespace std;
class CTexto
{
public:
	CTexto();
	~CTexto();
	vector<string> leerInformacion(string ruta);
	void escribirInformacion(string ruta, vector<string> datos);
	int retornarNumero(string ruta, int i);
};

CTexto::CTexto()
{
}

CTexto::~CTexto()
{
}

inline vector<string> CTexto::leerInformacion(string ruta)
{
	string linea;
	vector<string>textoCompleto;
	ifstream miarchivo(ruta);
	if (miarchivo.fail())
		cout << "Error";
	else
	{
		while (!miarchivo.eof())
		{
			getline(miarchivo, linea);
			textoCompleto.push_back(linea);
		}
		miarchivo.close();
	}
	return textoCompleto;
}

inline void CTexto::escribirInformacion(string ruta, vector<string> datos)
{
	ofstream miarchivo(ruta);
	if (miarchivo.fail())
		cout << "Archivo no existe";
	else {
		for (int i = 0; i < datos.size(); i++)
		{
			miarchivo << datos.at(i);
		}
		miarchivo.flush();
		miarchivo.close();
	}
}

inline int CTexto::retornarNumero(string ruta, int i)
{
	vector<string>datosleidos;
	fstream miarchvio(ruta);
	if (miarchvio.fail())
	{
		cout << "Error 0012";
	}
	else {
		datosleidos = leerInformacion(ruta);
	}
	return System::Convert::ToInt32(gcnew System::String(datosleidos[i].c_str()));
}