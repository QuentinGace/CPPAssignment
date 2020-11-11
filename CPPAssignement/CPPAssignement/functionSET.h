#if !(defined(__Function__))
#define __Function__
#include <string>

class Function
{
    protected :                                //attributes
        double fValue;
        int n;
    public :                                   //methods
        double get_fValue() const;
        //do we need a print function ?
                                 //default class destructor
};

class Set1 : public Function                   //inherent class of Function
{
    protected :                                //attributes
        
    public :   
        Set1(int n);                              //constructor
        double f0(double x);                      //methods
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