#if !(defined(__Function__))
#define __Function__
#include <string>
#include "matrix.h"

class Function
{
public:                                          // attributes
    int size;
    Matrix array;
    double v;
public:                                             // methods & constructor
    Function(double n, double v);
    double getElem(int x, int y) const;
    int getSize() const;
    void printTab();
    void setV(double v);
    double eFTBS(double Fi, double Fi1);
    double iFTBS(double Fi, double Fi1);
    ~Function() {};
};

class Set1 : public Function                        // Inherited class for SET1
{
protected:

public:
    Set1(double n, double v);
    Matrix init(double dx);                         // SET1 IC & BC
    Matrix analytical(double dx, double dt);        // SET1 analytic expression depending on (x,t)
    double f1(double x);                            // formula of f(x,0) so at t=0
    double f1A(double x, double t);                 // formula of f(x,t)
};

class Set2 : public Function                        // Inherited class for SET2
{
protected:

public:
    Set2(double n, double v);                                 
    Matrix init(double dx);                         // SET1 IC & BC
    Matrix analytical(double dx, double dt);        // SET1 analytic expression depending on (x,t)
    double f2(double x);                            // formula of f(x,0) so at t=0
    double f2A(double x, double t);                 // formula of f(x,t)
};

#endif