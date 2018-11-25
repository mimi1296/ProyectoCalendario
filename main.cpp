//main.cpp - Calendario equipos
#include "stdio.h"
#include "Manejador.h"


int main()
{
	std::string ae = "LigaEntrada.txt";
	std::string as = "LigaSalida.txt";
	std::cout << ae + as << std::endl;
	Manejador *X = Manejador::getInstance(ae,as);
	//std::cout << "Hola1" << std::endl;
	X->iniciar();
	//std::cout << std::to_string(MatrizCoo.getNumE()) << std::endl;
	
	return 0;
}