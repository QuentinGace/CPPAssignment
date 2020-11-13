#include "method.h"

double ExplicitFTBS::calc(double Fi, double Fi1)
{

	return Fi - v*(Fi - Fi1);
}

void NA_Method::setv(double v)
{
	this->v = v;
}

