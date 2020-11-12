// Assignment CPP Gr3
// Quentin Parmeshwari Luc A1 qwerty

#include <iostream>
#include <cmath>
#include "functionSET.h"

using namespace std;

<<<<<<< HEAD
//Lab1
double f0(double x);
double f1(double x);

double f0t(double x, double t);
double f1t(double x, double t);

double upwind(double f00, double f01); 			// f00 = f(n,i-1)  f01 = f(n,i)

int u = 1.75;
double dx = 0.8;                               // L = 100m [-50;50]
double dt = 0.5;
double v = u * dt / dx;
int n;


int main()
{
	cout << "Enter number of points :" << endl;
	cin >> n;
	

	double tab0[100][100]; 				// which stock f0 values
	double tab1[100][100];				// which stock f1 values

// 	INITIAL CONDITIONS at t=0

	tab0[0][0] = 0;
	for (int i = 1; i < 99; i++)
	{
		tab0[0][i] = f0(-40 + i * dx);
	}
	tab0[0][99] = 1;

	tab1[0][0] = 0;
	for (int i = 1; i < 99; i++)
	{
		tab1[0][i] = f1(-40 + i * dx);
	}
	tab1[0][99] = 1;

=======

int main()
{
	int N;										// number of points
	cout << "Enter the number of points we would take between [-50,50] :" << endl;
	cin >> N;	
>>>>>>> 69e90e162b19618d474263f7cb4ca75206f5b532

	double u = 1.75;							// speed sound u = 1.75 m/s 
	double dx = 100 / N;						// the step
	double dt = (dx / u) - 0.1;					// time time depending on CFL conditions
	double v = u * dt / dx;

<<<<<<< HEAD
	for (int n = 1; n < 100; n++)
	{
		tab0[n][0] = 0;
		for (int i = 1; i < 99; i++)
		{
			tab0[n][i] = upwind(tab0[n - 1][i - 1], tab0[n - 1][i]);
			//tab0[n][i] = central(tab0[n-1][i-1],tab0[n-1][i],tab0[n-1][i+1]);
		}
		tab0[n][99] = 1;
	}

	for (int n = 1; n < 100; n++)
	{
		tab1[n][0] = 0;
		for (int i = 1; i < 99; i++)
		{
			tab1[n][i] = upwind(tab1[n-1][i-1],tab1[n-1][i]);
			//tab1[n][i] = central(tab1[n - 1][i - 1], tab1[n - 1][i], tab1[n - 1][i + 1]);
		}
		tab1[n][99] = 1;
	}

	double tab0an[5][3];
	double tab1an[5][3];
=======
	cout << "dx = " << dx << "m" << " & dt = " << dt << " s" << endl;
>>>>>>> 69e90e162b19618d474263f7cb4ca75206f5b532

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
<<<<<<< HEAD

=======
>>>>>>> 69e90e162b19618d474263f7cb4ca75206f5b532
