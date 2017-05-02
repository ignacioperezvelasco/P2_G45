#pragma once
#include <vector>
#include <string>
#include <iostream>​
#include <algorithm>
#include <windows.h>
#include <set>

class Jugador
{
private:

	int score;
	std::vector<std::string>listajugador;			//Lista de elemento del jugador

public:
								

	Jugador();										//Constructor
	~Jugador();										//Destructor
	std::vector<std::string>inventario;
	void setScore(int);								//Metodo para establecer los puntos del jugador
	int getScore();									//Metodo para recoger los puntos del jugador
	void add(int);									//Metodo para añadir un elemento especifico
	void addBasics();								//Metodo para añadir los elementos basicos 
	void Delete(int);								//Metodo para eliminar un elemento especifico
	std::vector<std::string> getInv();				//Metodo para consultar el inventario del jugador
	void modListaJugador(std::string);				//Metodo para modificar la lista de elementos descubiertos del jugador
	//std::vector<std::string> getListaJugador();	//Metodo para recoger la lista del jugador
	std::string getStringElement(int);				//Consultar elemento con su numero
	void seeElementsInv();							//METODO PARA PRINTAR POR PANTALLA TODOS LOS ELEMENTOS DEL JUGADOR
	void sortElements();							//METODO PARA ORDENAR LOS ELEMENTOS DEL INVENTARIO
	void cleanElements();							//METODO PARA ELIMINAR TODOS LOS ELEMENTOS DEL INVENTARIO
};