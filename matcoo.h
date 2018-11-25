

#ifndef MATCOO_H_
#define MATCOO_H_

#include <iostream>
#include <vector>
#include <string>
#include "Ciudad.h"

class MatCoo
{
private:
	int numEquipos;
	int numMax;
	int numMin;
	std::vector<int> v;
	std::vector<int> f;
	std::vector<int> c;

public:
	MatCoo();
	~MatCoo();
	void setNumE(int num);
	void setMax(int num);
	void setMin(int num);
	void setValor(int i, int j, int val);
	int getNumE();
	int getMax();
	int getMin();
	int getValor(int i,int j);
	int getValorPos(int pos);
	int getsize();
	int getPosI(int pos);
	int getPosJ(int pos);
	void imprimirValores();
	void imprimirMatriz();
	void addValor(int val,int posi, int posj);	
	
};


#endif