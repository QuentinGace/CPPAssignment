// Assignment CPP Gr3
// Quentin Parmeshwari Luc A1 qwerty

#include <iostream>
#include <cmath>
#include "functionSET.h"

using namespace std;


int main()
{
	double N;										// number of points
	cout << "Enter the number of points we would take between [-50,50] :" << endl;
	cin >> N;	

	double u = 1.75;							// speed sound u = 1.75 m/s 
	double dx = 100 / N;						// the step
	double dtmax = (dx / u) ;					// time time depending on CFL conditions
	double dt=0;
	if (dtmax > 0.5) 
	{ 
		dt = 0.5; 
	}
	else if (dtmax > 0.25 && dtmax < 0.5) 
	{ 
		dt = 0.25; 
	}
	else if (dtmax > 0.1 && dtmax < 0.25)
	{
		dt = 0.1; 
	}
	else
	{
		cout << "ERROR the number of points is too high (inf 570)" << endl;
	}

	double v = u * dt / dx;

	cout << "dx = " << dx << " meter" << " & dt = " << dt << " s" << endl;

	Set1 Tab1{10.0};
		
	Tab1.printTab();						// also for Set1 Tab1An{tab1A};
	Tab1.getTab();
	Tab1.setTab(2);
	Tab1.printTab();
	Tab1.init(dx);

	/*for (int i; i < 100; i++)
	{
		cout << Tab1[i][0] << endl;
	}
	*/

	/*
	Set1 r(2);								// test object
	cout << r.f0(1.0) << endl;
	cout << r.f0A(-2.0,1.0) << endl;
	*/

	return 0;
}
