#if !(defined(__Function__))
#define __Function__
#include <string>
#include "matrix.h"

class Function
{
    protected :                                
        double fValue;
        //int n;
        //double table[100][100];
    public :                                   
        double get_fValue() const;
        
                                               
};

class Set1 : public Function
{
    protected:
        int size;
        Matrix array;
    public:
        Set1(double n);
        double getElem(int x, int y);
        void printTab();
        Matrix init(double dx);
        double f0(double x);
        double f0A(double x, double t);
        ~Set1();
        
};

class Set2 : public Function
{
    protected :                                //attributes
        
    public :   
        double f1(double x);                        //methods
        double f1A(double x, double t);             //constructor
};

#endif