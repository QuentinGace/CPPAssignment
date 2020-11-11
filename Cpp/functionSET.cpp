#include "../Header/functionSET.h"
#include <math.h>       //for exp()



Function::Function() : f(0), af(0) {}

Function::Function(func f) : f(f) {}

Function::Function(Afunc f) : af(f) {}

Function::Function(func f1, Afunc f2) : f(f1), af(f2) {}

Function& Function::setFunc(func f)
{
    f = f;
    return *this;
}

Function& Function::setAfunc(Afunc f)
{
    af = f;
    return *this;
}

void Function::display() const
{
    std::cout << "numerical : " << f << "analitical :" << af << std::endl;
}