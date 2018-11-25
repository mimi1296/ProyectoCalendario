//Manejador.cpp

#include "Manejador.h"

Manejador* Manejador::instance = 0;

Manejador* Manejador::getInstance(std::string ArchE, std::string ArchS) //retorna la instancia global del manejador
{
	if(instance == 0)
	{
		instance = new Manejador(ArchE,ArchS);
	}
	return instance;
}

Manejador::Manejador(){}

Manejador::Manejador(std::string ArchE, std::string ArchS) //Constructor
{
	ArchEntrada = ArchE;
	ArchSalida = ArchS;
}

Manejador::~Manejador(){}

MatCoo Manejador::cargarInfo()
{
	//Lee archivo y saca informacion en vector lineas
	std::ifstream archivo(ArchEntrada);
	std::string linea;
	std::vector<std::string> lineas;
	while(!archivo.eof())  //Lee el archivo
	{
		std::getline(archivo,linea);
		lineas.push_back(linea);
	}
	archivo.close();
	//std::cout << "Se ha logrado abrir el archivo" << std::endl;
	MatCoo MatrizInfo = MatCoo(); //Crea la matriz coordenada separando la informacion
	int cont = 0;
	int cont2 = 0;
	MatrizInfo.setNumE(atoi(lineas[0].c_str()));
	MatrizInfo.setMin(atoi(lineas[1].c_str()));
	MatrizInfo.setMax(atoi(lineas[2].c_str()));
	for(int i = 3; i < lineas.size(); i++)
	{
		cont2 = 0;
		std::string delimiter = "\t";
		size_t pos = 0;
		std::string token;
		while((pos = lineas[i].find(delimiter)) != std::string::npos)
		{
			token = lineas[i].substr(0,pos);
			//std::cout << token << std::endl;
			if(token == "-")
			{
				MatrizInfo.addValor(0, cont, cont2);
			}else{
				MatrizInfo.addValor(atoi(token.c_str()), cont, cont2);
			}
			
			lineas[i].erase(0, pos + delimiter.length());
			cont2 += 1;
		}
		cont += 1;
	}

	return MatrizInfo;
}

Calendario Manejador::programarFechas(Calendario unC)
{
	int i; 
	for(i=0; i < (unC.getNumEquipos()*unC.getNumEquipos()) ;i++)
	{
		//std::cout << "h"<< std::endl;
	}
	return unC;
}

void Manejador::iniciar() //inicia la informacion y actualiza los caminos no directos
{
	MatCoo unaM = this->cargarInfo();
	Calendario Calen = Calendario(unaM.getNumE(), unaM.getMax(), unaM.getMin(), unaM);
	Calen.actualizarCostos();
	

}