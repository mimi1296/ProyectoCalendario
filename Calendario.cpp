//Calendario.cpp
//Metodos de la clase Calendario
#include "Calendario.h"

Calendario* Calendario::instance = 0;

Calendario* Calendario::getInstance(int numE, int max, int min, MatCoo unaM) //Constructor Singleton: devuelve la instancia ya creada
{																				//sino la crea
	if(instance == 0)
	{
		instance = new Calendario( numE, max, min, unaM);
	}
	return instance;
}

Calendario::Calendario(int numE, int max, int min, MatCoo unaM)  //Constructor
{
	NumEquipos = numE;
	MaxGiras =  max,
	MinGiras = min;
	Costos = unaM;

	int i,j;		
	for(i=0;i< NumEquipos; i++)  //Se inicializa la mitad de la matriz calendario con -1s
	{
		std::vector<int> row;
		for(j=0;j< NumEquipos-1;j++)
		{
			row.push_back(-1);
		}
		Calen.push_back(row);
	}

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

std::vector<int> Calendario::organizarVector(int primero, std::vector<int> v)
{
	std::vector<int> nuevo;
	if(!v.empty())
	{
		
		std::vector<int>::iterator it;
		bool estado = false;
		for(it= v.begin(); it != v.end(); ++it)
		{
			if(*it == primero && estado == false)
			{
				estado = true;
			}
			if(estado == true)
			{
				nuevo.push_back(*it);
			}
		}
		for(it= v.begin(); it != v.end(); ++it)
		{
			if(!existe(*it,nuevo))
			{
				nuevo.push_back(*it);
			}
		}

	}
	return nuevo;
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
			std::cout <<std::to_string(Costos.getPosI(cont)) + ","+ std::to_string(Costos.getPosJ(cont)) + "sumaVal = " + std::to_string(sumaVal) << std::endl;
			Costos.setValor(Costos.getPosI(cont),Costos.getPosJ(cont), sumaVal);  //Se modifica el camino faltante en la matriz de costos
			Costos.setValor(Costos.getPosJ(cont),Costos.getPosI(cont), sumaVal);
		}
		

	}
	Costos.imprimirMatriz();
}

bool Calendario::existe(int val, std::vector<int> v)
{
	std::vector<int>::iterator it;
	bool ret = false;
	for(it= v.begin(); it != v.end(); ++it)
	{
		if(*it == val)
		{
			
			ret = true;
		}
	}
	return ret;
}

std::vector<int> Calendario::vecEquipos()
{
	std::vector<int> v;
	for(int cont=0; cont< NumEquipos; cont++)
	{
		v.push_back(NumEquipos-cont-1);
		//std::cout<< std::to_string(NumEquipos-cont-1);
	}
	//std::cout << ": v" <<std::endl;
	return v;
}

void Calendario::limpiarUnos()
{
	int i,j;
	for(j = 0; j < NumEquipos-1;j++ )
	{
		for(i=0;i<NumEquipos; i++)
		{
			if(Calen[i][j] == -1)
			{

				if(Calen[i-1][j] == NumEquipos-1)
				{
					Calen[i-1][j] -= 1;
					Calen[Calen[i-1][j]][j] = i-1;
					Calen[i][j] = NumEquipos-1;
					Calen[NumEquipos-1][j] = i;
					break;
				}	
			}
		}
	}
}

void Calendario::programarFechas()
{
	std::vector<int> v = this->vecEquipos();
	std::vector<int> vx;
	int equipo,cont,i,j;
	bool estado = false;
	for(i=0;i< NumEquipos;i++)
	{
		for(j=0;j< NumEquipos-1;j++)
		{
			if(estado == false) // Priera iteración
			{
				
				Calen[i][j] = v[j];
				Calen[v[j]][j] = i;
			}
			if(estado != false && Calen[i][j] == -1 && j == 0) // 
			{
				Calen[i][j] = v[i];
			}
		}
		estado = true;
	} // Se crea matriz con diag de 0 y primera fila y columna
	int din,n;
	n = NumEquipos-1;
	for(din = 1; din < (NumEquipos/2)-2; din++)
	{
		Calen[din][n-(2*din)] = n;
		Calen[din+3][n-(2*din)+1] = n;
	}

	/*for(i=0;i< NumEquipos;i++)
	{
		for(j=0;j< NumEquipos-1;j++)
		{
			if(Calen[i][j] == -1)
			{
				std::vector<int> fecha;
				for(cont=0;cont <NumEquipos; cont++) //Este nos devuelve la fila (fecha)
				{
					fecha.push_back(Calen[cont][j]);
				}

				//for para organizar con respecto a vx(vector organizado)
				std::vector<int> EquipoI = Calen[i];
				equipo = i;
				std::vector<int>::iterator it;
				vx = organizarVector(Calen[i][0],v);
				for(it = vx.begin(); it != vx.end(); ++it)
				{
					if(*it != equipo && false == this->existe(*it,EquipoI) && false == this->existe(*it,fecha))
					{

						Calen[i][j] =  *it;
						Calen[*it][j]= equipo;
						break;
					}
					
				}
				EquipoI.clear();
				fecha.clear();
				vx.clear();
			}
		}
		this->limpiarUnos();
	}*/


	//imprime para pruebas
	/*for(i=0;i< NumEquipos;i++)
	{
		for(j=0;j< NumEquipos-1;j++)
		{
			std::cout <<std::to_string(Calen[i][j]) +"\t";
		}
		std::cout <<"\n";
	}
	std::cout << "\n";*/


	for(j=0;j< NumEquipos-1;j++)
	{
		for(i=0;i< NumEquipos;i++)
		{
			std::cout <<std::to_string(Calen[i][j]) +"\t";
		}
		std::cout <<"\n";
	}
	std::cout << "\n";



}


