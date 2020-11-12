#if !(defined(__Function__))
#define __Function__
#include <string>

class Function
{
    protected :                                
        double fValue;
        int n;
        double table[400][400];
    public :                                   
        double get_fValue() const;
        
                                               
};

class Set1 : public Function
{
protected:
    
public:
    Set1(double table[400][400]);
        double init(int n, double dx);
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