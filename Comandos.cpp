#include "Comandos.h"

Comandos::Comandos(DataM & data, Jugador & jug):dataA(data), jugA(jug)
{

}

Comandos::~Comandos()
{
}

void Comandos::info(int element)
{
	std::string element_wiki(jugA.getStringElement(element));
	std::string url_wiki("https://en.wikipedia.org/wiki/" + element_wiki);

	char *url_arreglado = new char[url_wiki.length()];
	strcpy_s(url_arreglado, strlen(url_arreglado), url_wiki.c_str());

	ShellExecuteA(nullptr, "open", url_arreglado, nullptr, nullptr, SW_SHOWNORMAL);
}

void Comandos::help()
{
	std::cout << "Lista de comandos : " << std::endl;
	std::cout << "ADD + NUM_ELEMENTO :  Añade un elemento del inventario especificado por el numero" << std::endl;
	std::cout << "ADD BASICS : Añade todos los elementos principales al inventario" << std::endl;
	std::cout << "DELETE + NUM_ELEMENTO : Elimina un elemento del inventario especificado por el numero" << std::endl;
	std::cout << "INFO + NUM_ELEMENTO : Accede a Wikipedia para información del elemento especificado por numero" << std::endl;
	std::cout << "HELP : Muestra los comandos del juego" << std::endl;
	std::cout << "SORT : Ordena todos los elementos del inventario" << std::endl;
	std::cout << "CLEAN : Elimina todos los elementos del invetario" << std::endl;

}

void Comandos::sort()
{
	bool flag_orden(true);
	for (std::vector<std::string>::iterator it(jugA.getInv().begin()+1); it != jugA.getInv().end(); it++)
	{
		flag_orden = false;
		for (std::vector<std::string>::iterator it2(jugA.getInv().begin()); it2 != jugA.getInv().end(); it2++)
		{
			if (*(it2 + 1)<*it)
			{
				std::string a = (*it);
				*it = *(it + 1);
				*(it + 1) = a;
				flag_orden = true;
			}
		}
	}
}

void Comandos::clean()
{
	std::vector<std::string> a;
	bool flag_clean(true);

	for (std::vector<std::string>::iterator it(jugA.getInv().begin()); it != jugA.getInv().end(); it++)
	{
		for (std::vector<std::string>::iterator it2(jugA.getInv().begin()); it2 != jugA.getInv().end(); it2++)
		{
			if (*it == *it2)
			{
				flag_clean = true;
			}
		}
		if (flag_clean == true)
		{
			jugA.getInv().erase(it);
			flag_clean = false;
			it--;
		}
		else
		{
			a.push_back(*it);
		}
	}
}



std::string Comandos::getCombinationResult(std::string elem1, std::string elem2)
{
	
	std::pair<std::string, std::string> p = std::make_pair(elem1, elem2);
	std::pair<std::string, std::string> p2 = std::make_pair(elem2, elem1);

	if (dataA.mymap.find(p) != dataA.mymap.end()) {
		return dataA.mymap.find(p)->second;
	}
	else if (dataA.mymap.find(p2) != dataA.mymap.end()) {
		return dataA.mymap.find(p2)->second;
	}
	else {
		return "Not a Combination";
	}
}