// Assignment CPP Gr3
// Quentin Parmeshwari Luc 

#include <iostream>
#include <cmath>
#include "functionSET.h"
using namespace std;

int main()
{
	//***** Definition of the step values*****
	double N;									// number of points
	cout << "Enter the number of points we would take between [-50,50] :" << endl;
	cin >> N;	

	double u = 1.75;							// speed sound u = 1.75 m/s 
	double dx = 100 / N;						// the space step
	double dtmax = (dx / u) ;					// time step max depending on CFL conditions
	double dt=0;								// default value of the time step

	if (dtmax > 0.5) { dt = 0.5;}				// time step predifined value depending of N choosen to keep the stability
	else if (dtmax > 0.25 && dtmax < 0.5) { dt = 0.25;}
	else if (dtmax > 0.1 && dtmax < 0.25){dt = 0.1;}
	else {cout << "ERROR the number of points is too high (N > 571)" << endl;}

	double v = u * dt / dx;
	cout << "dx = " << dx << " meter" << " & dt = " << dt << " second" << endl;

	Set1 Tab1(N);								// object creation
	Set1 Tab1An{N};

	Tab1.init(dx);
	Tab1An.init(dx);
	Tab1.printTab();
	//Tab1.getElem(15, 0);

	cout << "Choose one Analytical method (1,2,3 or 4):" << endl;
	cout << "1. Explicit FTBS" << endl;
	cout << "2. Implicit FTBS" << endl;
	cout << "3. Lax-Wendroff" << endl;
	cout << "4. Richtmyer" << endl;

	char choice;
	cin >> choice;

	switch (choice)
	{
		case '1':
			cout << "Explicit FTBS" << endl;
			break;
		case '2':
			cout << "Implicit FTBS" << endl;
			break;
		case '3':
			cout << "Lax-Wendroff" << endl;
			break;
		case '4':
			cout << "Richtmyer" << endl;
			break;
	}

	return 0;
}
