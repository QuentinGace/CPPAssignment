#if !(defined(__Function__))
#define __Function__
#include <string>
#include "matrix.h"

class Function
{
public:                                                 // attributes
    int size;
    Matrix array;
    double v;
    double vr;
public:                                                 // methods & constructor
    Function(double n, double v);
    double getElem(int x, int y) const;                 // Get on element of the Matrix
    int getSize() const;
    void printTab();                                    // print the whole Matrix 
    void setV(double v);                                // Set the CFL condition
    void setVR(double v);                               // Set the CFL condition for Richtmyer (optional)
    double eFTBS(double Fi, double Fi1);                // The different methods     
    double iFTBS(double Fi, double Fi1);
    double LaxWendroff(double Fi, double Fi1, double Fi2);
    double Richtmyer(double Fi, double Fi1, double Fi2);
    ~Function() {};
};

class Set1 : public Function                            // Inherited class of Function for the Set1
{
protected:

public:
    Set1(double n, double v);
    Matrix init(double dx);                             // SET1 IC & BC
    Matrix analytical(double dx, double dt);            // SET1 analytic expression 
    double f1(double x);                                // formula of f(x,0) / t=0
    double f1A(double x, double t);                     // formula of f(x,t)
};

class Set2 : public Function                            // Inherited class of Function for the Set2
{
protected:

public:
    Set2(double n, double v);                                 
    Matrix init(double dx);                             // SET1 IC & BC
    Matrix analytical(double dx, double dt);            // SET1 analytic expression 
    double f2(double x);                                // formula of f(x,0) / t=0
    double f2A(double x, double t);                     // formula of f(x,t)
};

#endif