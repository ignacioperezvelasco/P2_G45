#include "Jugador.h"

Jugador::Jugador() :
	score(0),
	inventario({ "Air", "Earth", "Fire", "Water" })
	
{
}

Jugador::~Jugador()
{
}

void Jugador::addBasics()
{
	inventario.push_back("Air");
	inventario.push_back("Earth");
	inventario.push_back("Fire");
	inventario.push_back("Water");

}

void Jugador::add(int num)
{
	if (num <= 0)
	{
		std::cout << "No elements in that position." << std::endl;
		system("pause");
	}
	else if ((size() <num ))
	{
		std::cout << "No elements in that position." << std::endl;
		system("pause");
	}
	else { inventario.push_back(this->getStringElement(num)); }
}

void Jugador::Delete(int i)
{
	if (i <= 0) 
	{
		std::cout << "No elements in that position." << std::endl;
		system("pause");
	}
	else if ((size() <i)) {
		std::cout << "No elements in that position." << std::endl; 
		system("pause");
	}
	else
	{
		inventario.erase(inventario.begin() + i);
	}
}

void Jugador::setScore(int n)
{
	score = n;
}

int Jugador::getScore()
{
	return score;
}

std::vector<std::string> Jugador::getInv()
{
	return inventario;
}

void Jugador::modListaJugador(std::string elemento)
{
	listajugador.push_back(elemento);
}

/*std::vector<std::string> Jugador::getListaJugador()
{
	return listajugador;
}*/

std::string Jugador::getStringElement(int num)
{
	return inventario[num];
}

void Jugador::seeElementsInv()
{
	std::cout << "Your have this elements: " << std::endl;
	for (int i = 0; i < inventario.size(); i++)
	{
		std::cout << i + 1 << ".-  " << inventario[i] << std::endl;
	}
}

void Jugador::sortElements()
{
	std::sort(inventario.begin(), inventario.end());
}

void Jugador::cleanElements()
{
	sortElements();
	inventario.erase(std::unique(inventario.begin(), inventario.end()), inventario.end());
}

int Jugador::size() 
{
	int size=0;

	std::vector<std::string> aux = getInv();

	do
	{
		size++;
		aux.pop_back();

	} while (!aux.empty());

	return size;
}