#if !(defined(__Function__))
#define __Function__
#include <string>
#include "matrix.h"

class Function
{
protected:
    double fValue;
    //int n;
    //double table[100][100];
public:
    double get_fValue() const;


};

class Set1 : public Function
{
protected:
    int size;
    Matrix array;
    //string name;
public:
    Set1(double n);
    double getElem(int x, int y);
    void printTab();
    Matrix init(double dx);
    Matrix analytical(double dx, double dt);
    double f1(double x);
    double f1A(double x, double t);
    ~Set1();

};

class Set2 : public Function
{
protected:
    int size;
    Matrix array;
public:
    Set2(double n);
    double getElem(int x, int y);
    void printTab();
    Matrix init(double dx);
    Matrix analytical(double dx, double dt);
    double f2(double x);
    double f2A(double x, double t);
    ~Set2();
};

#endif