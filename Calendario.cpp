//Calendario.cpp
//Metodos de la clase Calendario
#include "Calendario.h"



Calendario::Calendario(int numE, int max, int min, MatCoo unaM)  //Constructor
{
	NumEquipos = numE;
	MaxGiras =  max,
	MinGiras = min;
	Costos = unaM;
}

Calendario::~Calendario()
{}

int Calendario::getNumEquipos()
{
	return NumEquipos;
}

int Calendario::getMaxGiras()
{
	return MaxGiras;
}

int Calendario::getMinGiras()
{
	return MinGiras;
}

MatCoo Calendario::getMatCostos()
{
	return Costos;
}

int Calendario::menorCosto(std::vector<Ciudad*> Nodo)  //Halla el Nodo con menor costo
{
	std::vector<Ciudad*>::iterator it;
	int min = INFINITO;
	int vertice,cont;
	for(cont=0; cont< Nodo.size(); cont++)
	{
		if(!(Nodo[cont]->estaMarcado()))
		{
			if(min > Nodo[cont]->getCosto())
			{
				min = Nodo[cont]->getCosto();
				vertice = Nodo[cont]->getNombre();
			}
		}
	}
	return vertice;
}


int Calendario::hayCamino(int i, int j) // Devuelve el camino minimo de ir de i a j (Dijkstra)
{
	int ret,x,cont;

	std::vector<Ciudad*> Nodo;
	for(cont=0; cont < NumEquipos; cont++)
	{
		Nodo.push_back(new Ciudad(cont));
	}
	Nodo[i]->marcar();
	Nodo[i]->setCosto(0);
		
	do   //mientras el nodo final no este marcado hace:
	{
		for(cont =0; cont < Costos.getsize(); cont++)
		{
			if(Costos.getPosI(cont) == i && Costos.getValorPos(cont) != 0)
			{
				if(!Nodo[Costos.getPosJ(cont)]->estaMarcado())
				{
					if( Nodo[Costos.getPosJ(cont)]->getCosto() > Costos.getValor(i,Costos.getPosJ(cont)) + Nodo[i]->getCosto())
					{
						Nodo[Costos.getPosJ(cont)]->setCosto(Costos.getValor(i,Costos.getPosJ(cont)) + Nodo[i]->getCosto());
						Nodo[Costos.getPosJ(cont)]->setPrevio(i);
					}
				}
			}
		}
		x = this->menorCosto(Nodo); //vertice con menor costo
		Nodo[x]->marcar();
		i = x;

	}while(!Nodo[j]->estaMarcado());
	ret = Nodo[j]->getCosto();
	Nodo.clear();
	return ret;
}

void Calendario::actualizarCostos()  //revisa la matriz coordenada en busqueda de caminos no existentes.
{
	int cont,cont2, cont3, sumaVal,anterior;
	std::vector<int> dir,original,camino;
	Costos.imprimirValores();
	

	for(cont= 0; cont < Costos.getsize(); cont++)
	{
		bool estado = false;
		sumaVal = 0;
		if((Costos.getPosI(cont) != Costos.getPosJ(cont)) && (Costos.getValorPos(cont) == 0))
		{
			sumaVal = this->hayCamino(Costos.getPosI(cont), Costos.getPosJ(cont));
			std::cout <<std::to_string(Costos.getPosI(cont)) + ","+ std::to_string(Costos.getPosJ(cont)) +"sumaVal = "+ std::to_string(sumaVal) << std::endl;
			Costos.setValor(Costos.getPosI(cont),Costos.getPosJ(cont), sumaVal);  //Se modifica el camino faltante en la matriz de costos
			Costos.setValor(Costos.getPosJ(cont),Costos.getPosI(cont), sumaVal);
		}
		

	}
	Costos.imprimirMatriz();
}


void Calendario::programarFecha()
{
	
}


