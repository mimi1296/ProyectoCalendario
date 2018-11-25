//Ciudad.cpp

#include "Ciudad.h"



Ciudad::Ciudad(){}

Ciudad::Ciudad(int unNombre) //Constructor
{
	Nombre =  unNombre; //numero de ciudad 
	Costo = INFINITO; //se inicia el costo de ir de i a este nodo como infinto hasta hallar el costo real
	Marcado = false;  //todos los nodos inician no marcados
	Previo = -1; // se inica el previo en -1, valor negativo para determinar si hay o no un nodo previo
}

Ciudad::~Ciudad(){}

int Ciudad::getNombre()
{
	return Nombre;
}

int Ciudad::getCosto()
{
	return Costo;
}

void Ciudad::marcar()
{
	Marcado = true;
}

void Ciudad::setCosto(int unCosto)
{
	Costo = unCosto;
}

void Ciudad::sumarCosto(int unCosto)
{
	Costo += unCosto;
}


bool Ciudad::estaMarcado()
{
	return Marcado;
}

int Ciudad::getPrevio()
{
	return Previo;
}

void Ciudad::setPrevio(int unaC)
{
	Previo = unaC;
}