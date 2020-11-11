// Assignment CPP Gr3
//Quentin Parmeshwari Luc
#include "../Header/functionSET.h"


int u = 1;
double dx = 0.8;
double dt = 0.5;
double v = u*dt/dx;

double Set1(double x);
double ASet1(double x, double t);
double sign(double x);


int main()
{
    Function f1(Set1);
    Function Af1(ASet1);
    f1.display();
    return 0;
}


double Set1(double x)
{
    return (sign(x)+1)/2;
}

double ASet1(double x, double t)
{
    return (sign(x-1.75*t)+1)/2;
}

double sign(double x)
{
	if (x<0) return 0;
	if (x==0) return 0.5;
	else return 1;
}