// Assignment CPP Gr3
// Quentin Parmeshwari Luc A1 qwerty

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int n;										// number of points
	cout << "Enter the number of point we would take between [-50,50] :" << endl;
	cin >> n;	

	double u = 1.75;							// speed sound u = 1.75 m/s 
	double dx = 100 / n;						// the step
	double dt = (dx / u) - 0.1;							// time time depending on CFL conditions
	double v = u * dt / dx;



	return 0;
}
