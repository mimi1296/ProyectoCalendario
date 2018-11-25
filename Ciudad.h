//Ciudad.h
#ifndef CIUDAD_H_
#define CIUDAD_H_

#define INFINITO 1000000000
#include "matcoo.h"


class Ciudad
{
private:
	//Atributos:
	int Nombre;
	int Costo;
	bool Marcado;
	int Previo; 

public:
	//Metodos
	Ciudad();
	Ciudad(int Nombre);
	~Ciudad();
	int getNombre();
	int getCosto();
	void marcar();
	void setCosto(int unCosto);
	void sumarCosto(int unCosto);
	bool estaMarcado();
	int getPrevio();
	void setPrevio(int unaC);

	
};


#endif 