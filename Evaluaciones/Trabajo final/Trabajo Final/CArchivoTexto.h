#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class CArchivoTexto
{
private:

public:
	CArchivoTexto();
	~CArchivoTexto();
	vector<string> LeerDesdeArchivo(string ruta_archivo);
	vector<vector<int>> LeerObstaculos(string ruta_archivo);
	void GrabarEnArchivo(string ruta_archivo, vector<string> datoagrabar);
	int retornarNumero(string ruta, int fila);
};

