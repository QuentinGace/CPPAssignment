#if !(defined(__Function__))
#define __Function__
#include <string>
#include "matrix.h"

class Function
{
protected:
    int size;
    Matrix array;
public:
    Function(double n);
    double getElem(int x, int y) const;
    void printTab();
    ~Function() {};
};

class Set1 : public Function
{
protected:

public:
    Set1(double n);
    Matrix init(double dx);
    Matrix analytical(double dx, double dt);
    double f1(double x);
    double f1A(double x, double t);
};

class Set2 : public Function
{
protected:

public:
    Set2(double n);
    Matrix init(double dx);
    Matrix analytical(double dx, double dt);
    double f2(double x);
    double f2A(double x, double t);
};

#endif