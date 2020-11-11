#include "functionSET.h"
#include <math.h>       //for exp()

//***** TO DO : define all the methods *****

double Function::get_fValue() const
{
	return(fValue);
}

double Function::norm1(double fValue)
{
    return 0;
}

double Function::norm2(double fValue)
{
    return 0;
}

double Function::norm3(double fValue)
{
    return 0;
}

double Function::square(double fValue)
{
    return 0.0;
}


Set1::Set1(double x, double t)
{

}

double Set1::sign(double x)
{
    return 0;
}

Set2::Set2(double x, double t)
{
    fValue = exp(x);
}