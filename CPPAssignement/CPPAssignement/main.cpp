// Assignment CPP Gr3
// Quentin Parmeshwari Luc

#include <iostream>
#include <cmath>

using namespace std;

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


	// 	x from [-40,40] with a step of dx = 0.8
	// 	choose either upwind or central method 

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


	tab0an[0][0], tab1an[0][0] = f0t(-40, 5), f1t(-40, 5);
	tab0an[1][0], tab1an[1][0] = f0t(-20, 5), f1t(-20, 5);
	tab0an[2][0], tab1an[2][0] = f0t(0, 5), f1t(0, 5);
	tab0an[3][0], tab1an[3][0] = f0t(20, 5), f1t(20, 5);
	tab0an[4][0], tab1an[4][0] = f0t(40, 5), f1t(40, 5);

	tab0an[0][1], tab1an[0][1] = f0t(-40, 10), f1t(-40, 10);
	tab0an[1][1], tab1an[1][1] = f0t(-20, 10), f1t(-20, 10);
	tab0an[2][1], tab1an[2][1] = f0t(0, 10), f1t(0, 10);
	tab0an[3][1], tab1an[3][1] = f0t(20, 10), f1t(20, 10);
	tab0an[4][1], tab1an[4][1] = f0t(40, 10), f1t(40, 10);

	tab0an[0][2], tab1an[0][2] = f0t(-40, 20), f1t(-40, 20);
	tab0an[1][2], tab1an[1][2] = f0t(-20, 20), f1t(-20, 20);
	tab0an[2][2], tab1an[2][2] = f0t(0, 20), f1t(0, 20);
	tab0an[3][2], tab1an[3][2] = f0t(20, 20), f1t(20, 20);
	tab0an[4][2], tab1an[4][2] = f0t(40, 20), f1t(40, 20);

	// Print the values of both tables

	cout << "t = 5" << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << "f0(" << -40 + (i + 1) * dx << ",5) = " << tab0[10][i] << "	:: f1(" << -40 + (i + 1) * dx << ",5) = " << tab1[10][i] << endl;
	}

	cout << "t = 10" << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << "f0(" << -40 + (i + 1) * dx << ",10) = " << tab0[20][i] << "	:: f1(" << -40 + (i + 1) * dx << ",10) = " << tab1[20][i] << endl;
	}

	cout << "t = 20" << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << "f0(" << -40 + (i + 1) * dx << ",20) = " << tab0[40][i] << "	:: f1(" << -40 + (i + 1) * dx << ",20) = " << tab1[40][i] << endl;
	}

	cout << "analytical solutions" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "f0.an(" << -40 + (20 * i) << "," << (j + 1) * 5 << ") = " << tab0an[i][j] << "	:: f1.an(" << -40 + (20 * i) << "," << (j + 1) * 5 << ") = " << tab1an[i][j] << endl;
		}
	}
	return 0;

}


double f0(double x)							// return directly the result of (1/2)*(sign(x) + 1) 
{
	if (x < 0) return 0;
	else if (x == 0) return 0.5;
	else return 1;
}

double f1(double x)
{
	return 0.5 * exp(-1 * (x * x));
}

double upwind(double f00, double f01)
{
	return v * f00 + (1 - v) * f01;			// f(n+1,i) = v*f(n,i-1) + (1-v)*f(n,i)
}


double f0t(double x, double t)
{
	if ((x - t) < 0) return 0;
	if ((x - t) == 0) return 0.5;
	else return 1;
}

double f1t(double x, double t)
{
	return 0.5 * exp(-1 * (x - t) * (x - t));
}

