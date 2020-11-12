#if !(defined(__Method__))
#define __Method__
#include <string>

class NA_Method
{
	protected:
		double v;
	public:
		void setv(double v);
        

};

class ExplicitFTBS : public NA_Method
{
	protected:                                //attributes

	public:
		double calc(double Fi, double Fi1); //methods
											//constructor
}; 

class ImplicitFTBS : public NA_Method
{
protected:

public:

};


#endif
