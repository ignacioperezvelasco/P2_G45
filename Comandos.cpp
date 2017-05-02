#include "Comandos.h"

Comandos::Comandos(DataM & data, Jugador & jug):dataA(data), jugA(jug)
{

}

Comandos::~Comandos()
{
}

void Comandos::info(int element)
{
	std::string url;
	std::string info = jugA.getStringElement(element);

	url = "https://en.wikipedia.org/wiki/" + info;
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void Comandos::help()
{
	std::cout << "-------------------" << std::endl;
	std::cout << "FULLENTI ALCHEMIST" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "- Enter the word a 'add'. You can choose the 4 elements (basics) or an especific element (number)" << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
	std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the instances of all the repeated elements" << std::endl;
	std::cout << "- Enter the word 'combine' to combine two elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	system("pause");

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
		return "Fail";
	}
}