//main.cpp - Calendario equipos
#include "stdio.h"
#include "Manejador.h"


int main()
{
	std::string ae = "LigaEntrada.txt";
	std::string as = "LigaSalida.txt";
	Manejador *X = Manejador::getInstance(ae,as);  //se crea un unico manejador global. 
	//std::cout << "Hola1" << std::endl;
	X->iniciar();  
	//std::cout << std::to_string(MatrizCoo.getNumE()) << std::endl;
	
	return 0;
}