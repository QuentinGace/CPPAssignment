#include "functionSET.h"
#include <math.h>       //for exp()
#include<iostream>

using namespace std;

//***** TO DO : define all the methods *****

double Function::get_fValue() const
{
	return fValue;
}


double Set1::f0(double x)
{
	if (x < 0) return 0;
	if (x == 0) return 0.5;
	else return 1;
}

double Set1::f0A(double x, double t)
{
	if ((x - 1.75) < 0) return 0;
	if ((x - 1.75) == 0) return 0.5;
	else return 1;
}

Set1::Set1(int n)
{
	this->size = n;
	this->array = Matrix(n);
}

Matrix Set1::getTab()
{
	return this->array;
}

void Set1::printTab()
{
	std::cout << array << endl;
}


Matrix Set1::init(double dx)
{
	array[0][0] = 0;						// Init for t = 0
	for (int i = 1; i < size; i++)
	{
		array[i][0] = f0(-50 + i * dx);
	}
	array[size][0] = 1;

	return array;
}

Set1::~Set1()
{
	cout << "Destruction" << endl;
}

double Set2::f1(double x)
{
	return 0.5 * exp(-1 * (x * x));
}

double Set2::f1A(double x, double t)
{
	return 0.5 * exp(-1 * (x - 1.75) * (x - 1.75));
}
