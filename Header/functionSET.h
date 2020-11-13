#include "matrix.h"

typedef double (* func)(double x);
typedef double (* Afunc)( double x, double y );

class Function
{
    public :                                //attributes
        func f;                             //f(x)     -> numerical function
        Afunc af;                           //f(x,t)   -> analitical function
    

    public :                                //methods
        //4 constructors
        Function();
        Function(func f);
        Function(Afunc f);
        Function(func f1, Afunc f2);

        Function& setFunc(func f);
        Function& setAfunc(Afunc f);

        void display() const;
        ~Function(){};                      //default class destructor
};
