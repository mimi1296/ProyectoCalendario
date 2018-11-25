//Calendario.h

#ifndef CALENDARIO_H_
#define CALENDARIO_H_

//Clase Calendario: es la principal en el modelo 

#include "matcoo.h"

class Calendario
{

private:

	static Calendario* instance;  //Patron singleton
	Calendario(int numE, int max, int min, MatCoo unaM);


	int NumEquipos;
	int MaxGiras;
	int MinGiras;
	MatCoo Costos; //Matriz coordenada de costos
	std::vector<std::vector<int>> Calen;  // Calendario 


	
public:
	  
	~Calendario();
	static Calendario* getInstance(int numE, int max, int min, MatCoo unaM);

	int getNumEquipos();
	int getMaxGiras();
	int getMinGiras();
	MatCoo getMatCostos();
	int menorCosto(std::vector<Ciudad*> Nodo);
	int hayCamino(int i, int j); 
	void actualizarCostos();
	void programarFechas();





	
};
#endif