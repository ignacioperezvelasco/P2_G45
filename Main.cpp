#include <fstream>
#include <iostream> 
#include <string>
#include <fstream>
#include <unordered_map>
#include <conio.h>
#include "Comandos.h"
#include "Jugador.h"
#include "DataM.h"

int main()

{
	char c;
	int score_jug=0;
	std::string input;
	std::string input2;

	std::string element1;
	std::string element2;
	std::string element3;
	int user_Input_ELEMENT1;
	int user_Input_ELEMENT2;
	int user_Input_ELEMENT3;
	std::string url_elements("elements.dat");

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
	system("cls");


	DataM data(url_elements);
	Jugador jug;
	Comandos com(data, jug);

	while (true) {

		/*c = _getch();
		if (c == 27)
		flag_salida = true;*/

		std::cout << "Your current score is: " << jug.getScore() << std::endl;

		jug.seeElementsInv();
		std::cin >> input;

		if (input == "add")
		{
			std::cout << "Basics or put the number of the element: " << std::endl;
			std::cin >> input2;
			if (input2 == "basics" || input2 == "Basics")
			{
				jug.addBasics();
			}
			else
			{
				jug.add(std::stoi(input2) - 1);
			}
		}
		else if (input == "delete")
		{
			std::cout << "Put the number of the element: " << std::endl;
			std::cin >> input2;
			jug.Delete(std::stoi(input2) - 1);
		}
		else if (input == "info")
		{
			std::cout << "Put the number of the element: " << std::endl;
			std::cin >> input2;
			com.info(std::stoi(input2) - 1);
		}
		else if (input == "clean") {
			//com.clean();
			jug.cleanElements();
		}
		else if (input == "help")
		{
			com.help();
		}
		else if (input == "sort")
		{
			//com.sort();
			jug.sortElements();
		}
		else if (input == "combine")
		{
			std::cout << "Put the number of the first element: " << std::endl;
			std::cin >> element1;
			std::cout << "Put the number of the second element: " << std::endl;
			std::cin >> element2;
			if (element1 == element2) { std::cout << "Impossible combine two elements with the same position." << std::endl; system("pause"); }
			else {
				user_Input_ELEMENT1 = (std::stoi(element1)) - 1;
				user_Input_ELEMENT2 = (std::stoi(element2)) - 1;


				element1 = jug.getStringElement(user_Input_ELEMENT1);
				element2 = jug.getStringElement(user_Input_ELEMENT2);

				element3 = com.getCombinationResult(element1, element2);

				if (element3 == "Fail")
				{
					std::cout << element3 << std::endl;
				}
				else
				{
					//user_Input_ELEMENT3 = (std::stoi(element3)) - 1;

					if (user_Input_ELEMENT1 < user_Input_ELEMENT2)			//EN CASO QUE LOS ELEMENTOS TENGAN DISTINTA POSICION EN EL VECTOR(PARA QUE NO EXPLOTE EL PROGRAMA)
					{
						jug.Delete(user_Input_ELEMENT1);
						jug.Delete(user_Input_ELEMENT2 - 1);
					}
					else
					{
						jug.Delete(user_Input_ELEMENT1 - 1);
						jug.Delete(user_Input_ELEMENT2);
					}

					jug.inventario.push_back(element3);
					//jug.add(std::stoi(user_Input_ELEMENT3));			//NO ENTENDEMOS POR QUE NO SALTA ERROR (NOS INDICA QUE NOS DIRECCIONAMOS A UNA DIRECCION QUE NO EXISTE)

					//AUMENTAMOS LA SCORE DEL JUGADOR
					score_jug = score_jug++;
					jug.setScore(score_jug);
				}
			}
			}
		system("cls");



	}

	//COMPROBACION DE SI FUNCIONA O NO LA LECUTRA DE ELEMENTS.DAT
	/*for (auto it = data.mymap.begin(); it != data.mymap.end(); ++it) {
		std::cout <<it->second<<"="<< it->first.first<< "+" << it->first.second<< std::endl;//" " << ":" << it->second;
		
	}*/

	system("pause");



}
