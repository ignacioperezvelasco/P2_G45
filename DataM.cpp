#include "DataM.h"
#include <fstream>
#include <iostream> 
#include <string>
#include <fstream>
#include <unordered_map>



DataM::DataM(std::string URL)
{
	int igual;
	int suma;
	int counter = 0;
	std::string palabras[3];

	std::ifstream fichero;
	std::string aux;

	fichero.open(URL);

	if (fichero.fail())
	{
		system("pause");
	}

	while (std::getline(fichero, aux))
	{
		igual = aux.find("=");
		suma = aux.find("+");

		palabras[0] = aux.substr(0, igual - 1);
		palabras[1] = aux.substr(igual + 2, (suma - 3) - igual);
		palabras[2] = aux.substr(suma + 2);

		mymap[{palabras[1], palabras[2]}] = { palabras[0] };
	}

	fichero.close();
}
DataM::~DataM()
{
}