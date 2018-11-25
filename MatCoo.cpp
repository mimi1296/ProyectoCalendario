//MatCoo.cpp

#include "matcoo.h"

MatCoo::MatCoo(){}	

MatCoo::~MatCoo(){}

void MatCoo::setNumE(int num)
{
	numEquipos = num;
}

void MatCoo::setMax(int num)
{
	numMax = num;
}

void MatCoo::setMin(int num)
{
	numMin = num;
}

void MatCoo::setValor(int i, int j, int val)
{
	for(int cont = 0; cont < this->getsize(); cont++)
	{
		if(i == f[cont] && j == c[cont])
		{
			v[cont] = val;
		}
	}
}

int MatCoo::getNumE()
{
	return numEquipos;
}

int MatCoo::getMax()
{
	return numMax;
}

int MatCoo::getMin()
{
	return numMin;
}

int MatCoo::getsize()
{
	return v.size();
}

int MatCoo::getPosI(int pos)
{
	return f[pos];
}

int MatCoo::getPosJ(int pos)
{
	return c[pos];
}

int MatCoo::getValor(int i, int j)
{
	if(i <= numEquipos && j <= numEquipos)
	{
		for(int cont = 0; cont < v.size(); cont++)
		{
			if(f[cont] == i && c[cont] == j)
			{
				return v[cont];
			}
		}
	}
	else{
		return 0;
	}
	
	
}

int MatCoo::getValorPos(int pos)
{
	return v[pos];
}

void MatCoo::addValor(int val, int posi, int posj)
{
	v.push_back(val);
	f.push_back(posi);
	c.push_back(posj);
}

void MatCoo::imprimirValores()
{
	int i;
	std::cout <<"Val:	";
	for(i = 0;i< v.size();i++)
	{
		std::cout <<  std::to_string(v[i]) + "," ;
	}
	std::cout << std::endl;
	std::cout <<"Fil:	" ;
	for(i = 0;i< v.size();i++)
	{
		std::cout << std::to_string(f[i]) + ",";
	}
	std::cout << std::endl;
	std::cout <<"Col:	";
	for(i = 0;i< v.size();i++)
	{
		std::cout << std::to_string(c[i]) +"," ;
	}
	std::cout << std::endl;
}

void MatCoo::imprimirMatriz()
{
	int i,j;
	for( i=0; i < this->getNumE(); i++)
	{
		for( j =0; j <this->getNumE(); j++)
		{
			std::cout << "	" + std::to_string(this->getValor(i,j));
		}
		std::cout<< "\n";
	}
}

