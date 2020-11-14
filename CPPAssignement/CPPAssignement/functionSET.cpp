#include "functionSET.h"
#include <math.h>       //for exp()
#include<iostream>
#include <string>

using namespace std;


/*****	Methods and Constructors for the Function class	 *****/


Function::Function(double n, double v)							// constructor on the mother class
{
	this->size = static_cast<int>(n);					// represent the size of the matrix with n, to fill up the matrix elements	
	this->array = Matrix(static_cast<int>(n + 1));		// matrix definition
	this->v = v;
}

double Function::getElem(int x, int y) const			// to get any value of the array
{
	cout << array[x][y] << endl;
	return this->array[x][y];
}

int Function::getSize() const
{
	return this->size;
}

void Function::printTab()								// to print one entire array
{
	std::cout << array << endl;
}

void Function::setV(double v)
{
	this->v = v;
}

double Function::eFTBS(double Fi, double Fi1)
{
	return Fi - v * (Fi - Fi1);
}

double Function::iFTBS(double Fi, double Fi1)// *****TO DO*******
{
	return 0;
}
/*****	Methods and Constructors for Set1 Inherited class	 *****/


Set1::Set1(double n, double v) :Function(n,v)						//call the constructor from the main class
{
}

Matrix Set1::init(double dx)
{
	for (int i = 1; i < size; i++)						// Initial Conditions at t=0
	{
		array[i][0] = f1(-50 + i * dx);
	}
	for (int j = 0; j <= size; j++)						// Boundaries Conditions at x=-50 & x=50 (for every t)
	{
		array[0][j] = 0;
		array[size][j] = 1;
	}
	return array;
}

Matrix Set1::analytical(double dx, double dt)			// Analytical formula depending on x & t
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			array[i][j] = f1A(-50 + i * dx, j * dt);
		}
	}
	return array;
}

double Set1::f1(double x)
{
	if (x < 0) return 0;
	if (x == 0) return 0.5;
	else return 1;
}

double Set1::f1A(double x, double t)
{
	if ((x - 1.75 * t) < 0) return 0;
	if ((x - 1.75 * t) == 0) return 0.5;
	else return 1;
}


/*****	Methods and Constructors for Set2 Inherited class  *****/


Set2::Set2(double n, double v) :Function(n,v)						//call the constructor from the main class
{
}

Matrix Set2::init(double dx)
{
	for (int i = 1; i < size; i++)						// Initial Conditions at t=0
	{
		array[i][0] = f2(-50 + i * dx);
	}
	for (int j = 0; j <= size; j++)						// Boundaries Conditions at x=-50 & x=50 (for every t)
	{
		array[0][j] = 0;
		array[size][j] = 0;
	}
	return array;
}

Matrix Set2::analytical(double dx, double dt)			// Analytical formula depending on x & t
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			array[i][j] = f2A(-50 + i * dx, j * dt);
		}
	}
	return array;
}

double Set2::f2(double x)
{
	return 0.5 * exp(-1 * (x * x));
}

double Set2::f2A(double x, double t)
{
	return 0.5 * exp(-1 * (x - 1.75 * t) * (x - 1.75 * t));
}