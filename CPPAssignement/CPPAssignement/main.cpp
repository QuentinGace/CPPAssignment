// Assignment CPP Gr3
// Quentin Parmeshwari Luc A1 qwerty

#include <iostream>
#include <cmath>
#include "functionSET.h"

using namespace std;


int main()
{
	int N;										// number of points
	cout << "Enter the number of points we would take between [-50,50] :" << endl;
	cin >> N;	

	double u = 1.75;							// speed sound u = 1.75 m/s 
	double dx = 100 / N;						// the step
	double dt = (dx / u) - 0.1;					// time time depending on CFL conditions
	double v = u * dt / dx;

	cout << "dx = " << dx << "m" << " & dt = " << dt << " s" << endl;


	Set1 Tab0{};
	//Set1 tab0An{tab0An};
	Tab0 = Tab0.init(N, dx);

	cout << Tab0.init(N,dx) << endl;








	Set1 r(2);								// test object
	cout << r.f0(1.0) << endl;
	cout << r.f0A(-2.0,1.0) << endl;

	return 0;
}
