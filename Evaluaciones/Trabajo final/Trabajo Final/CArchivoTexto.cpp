#include "CArchivoTexto.h"

CArchivoTexto::CArchivoTexto()
{
}

CArchivoTexto::~CArchivoTexto()
{
}

vector<string> CArchivoTexto::LeerDesdeArchivo(string ruta_archivo)
{
	string linea;
	vector<string>resultado;
	ifstream miarchivo(ruta_archivo);
	if (miarchivo.fail())
		cout << "Error al abrir el documento";
	else
	{
		while (!miarchivo.eof())
		{
			getline(miarchivo, linea);
			resultado.push_back(linea);
		}
		miarchivo.close();
	}
	return resultado;
}

vector<vector<int>> CArchivoTexto::LeerObstaculos(string ruta_archivo)
{
	string linea;
	vector < vector<int>> resultado;
	ifstream miarchivo(ruta_archivo);
	vector<int> mini;
	int a, b, c, d;
	char ch;
	if (miarchivo.fail())
		cout << "Error al abrir el documento";
	else
	{
		while (!miarchivo.eof())
		{
			getline(miarchivo, linea);
			stringstream ss(linea);
			ss >> a >> ch >> b >> ch >> c >> ch >> d;
			mini.push_back(a);
			mini.push_back(b);
			mini.push_back(c);
			mini.push_back(d);
			resultado.push_back(mini);
			mini.clear();
		}
		miarchivo.close();
	}
	return resultado;
}

void CArchivoTexto::GrabarEnArchivo(string ruta_archivo, vector<string> datoagrabar)
{
	ofstream miarchivo(ruta_archivo);
	//ofstream miarchivo(ruta_archivo, std::ofstream::app); //LOS DATOS NUEVOS LOS COLOCA AL FINAL. MANTIENE LO ANTERIOR
	if (miarchivo.fail())
		cout << "Archivo no existe";
	else {
		for (int i = 0; i < datoagrabar.size(); i++)
		{
			miarchivo<<datoagrabar.at(i);
		}
		miarchivo.flush();
		miarchivo.close();
	}
}

int CArchivoTexto::retornarNumero(string ruta, int fila)
{
	vector<string>datosleidos;
	fstream miarchvio(ruta);
	if (miarchvio.fail())
	{
		cout << "Error 0012";
	}
	else {
		datosleidos = LeerDesdeArchivo(ruta);
	}
	return System::Convert::ToInt32(gcnew System::String(datosleidos[fila].c_str()));
}
