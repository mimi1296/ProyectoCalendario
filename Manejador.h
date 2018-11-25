//Manejador.h

//Codigo inicial del proyecto final POO

#ifndef MANEJADOR_H_
#define MANEJADOR_H_

#include "matcoo.h"
#include "fstream"
#include "Calendario.h"

class Manejador
{
private:
	std::string ArchEntrada;
	std::string ArchSalida;
	static Manejador* instance; //Patron Singleton
	Manejador();  //Constructores privados para evitar diferentes manejadores
	Manejador(std::string ArchE, std::string ArchS);

public:
	~Manejador();
	static Manejador* getInstance(std::string ArchE, std::string ArchS);
	Calendario programarFechas(Calendario unC);
	MatCoo cargarInfo();
	void iniciar();
	
};

#endif 