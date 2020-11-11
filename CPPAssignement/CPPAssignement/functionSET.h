

class Function
{
    protected :                                //attributes
        double fValue;
        int n;
    public :                                   //methods
        double get_fValue() const;
                                          //do we need a print function ?
        ~Function(){};                         //default class destructor
};

class Set1 : public Function                   //inherent class of Function
{
    protected :                                //attributes
        
    public :   
        Set1(n);
        double f0(double x);                      //methods
        double f0A(double x, double t);           //constructor
        
};

class Set2 : public Function
{
    protected :                                //attributes
        
    public :   
        double f1(double x);                        //methods
        double f1A(double x, double t);             //constructor
};