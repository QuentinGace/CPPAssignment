

class Function
{
    public :                                //attributes
        double fValue;
    public :                                //methods
        double get_fValue() const;
        double norm1(double fValue);
        double norm2(double fValue);
        double norm3(double fValue);
        double square(double fValue);
        //do we need a print function ?
        ~Function(){};                      //default class destructor
};

class Set1 : public Function                //inherent class of Function
{
    public :                                //attributes

    public :                                //methods
        Set1(double x, double t);           //constructor
        double sign(double x);
};

class Set2 : public Function
{
    public :                                //attributes

    public :                                //methods
        Set2(double x, double t);           //constructor
};