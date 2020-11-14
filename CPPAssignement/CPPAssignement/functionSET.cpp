#include "functionSET.h"
#include <math.h>       //for exp()
#include<iostream>
#include <string>

using namespace std;

//***** TO DO : define all the methods *****

Function::Function(double n)
{
	this->size = static_cast<int>(n);
	this->array = Matrix(static_cast<int>(n + 1));
}

double Function::getElem(int x, int y) const
{
	cout << array[x][y] << endl;
	return this->array[x][y];
}

void Function::printTab()
{
	//std::cout << name << endl;
	std::cout << array << endl;
}


Set1::Set1(double n)								//call the constructor from the main class
	:Function(n)
{
}

Matrix Set1::init(double dx)
{
	for (int i = 1; i < size; i++)					// Initial Conditions at t=0
	{
		array[i][0] = f1(-50 + i * dx);
	}
	for (int j = 0; j <= size; j++)					// Boundaries Conditions at x=-50 & x=50
	{
		array[0][j] = 0;
		array[size][j] = 1;
	}
	return array;
}

Matrix Set1::analytical(double dx, double dt)
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

Set2::Set2(double n)								//call the constructor from the main class
	:Function(n)
{
}

Matrix Set2::init(double dx)
{
	for (int i = 1; i < size; i++)					// Initial Conditions at t=0
	{
		array[i][0] = f2(-50 + i * dx);
	}
	for (int j = 0; j <= size; j++)					// Boundaries Conditions at x=-50 & x=50
	{
		array[0][j] = 0;
		array[size][j] = 0;
	}
	return array;
}

Matrix Set2::analytical(double dx, double dt)
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