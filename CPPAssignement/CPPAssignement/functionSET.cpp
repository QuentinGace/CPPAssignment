#include "functionSET.h"
#include <math.h>       //for exp()

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
	if ((x - t) < 0) return 0;
	if ((x - t) == 0) return 0.5;
	else return 1;
}

double Set2::f1(double x)
{
	return 0.5 * exp(-1 * (x * x));
}

double Set2::f1A(double x, double t)
{
	return 0.5 * exp(-1 * (x - t) * (x - t));
}
