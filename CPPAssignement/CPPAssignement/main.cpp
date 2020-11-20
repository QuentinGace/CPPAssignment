// Assignment CPP Gr3 : Quentin Parmeshwari Luc 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "functionSET.h"
using namespace std;

int main()
{
	ofstream myfile5;										// open the files where we would store our result for t=5 
	ofstream myfile10;										// & t=10


	/*****		Definition of the step values		*****/

	double N;												// number of points

	cout << "Enter the number of points we would take between [-50,50] :" << endl;
	cin >> N;	

	double u = 1.75;										// speed sound u = 1.75 m/s 
	double dx = 100 / N;									// the space step
	double dtmax = (dx / u) ;								// time step max depending on CFL conditions
	double dt=0;											// default value of the time step

	if (dtmax > 0.5) { dt = 0.5;}							// time step predifined value depending of N choosen to keep the stability
	else if (dtmax > 0.25 && dtmax < 0.5) { dt = 0.25;}
	else if (dtmax > 0.1 && dtmax < 0.25){dt = 0.1;}
	else {cout << "ERROR the number of points is too high (N > 571)" << endl;}

	double v = u * dt / dx;
	cout << "dx = " << dx << " meter(s)" << " & dt = " << dt << " second(s)" << endl;


	/*******	Object creation	+ IC & BC setting up	*******/

	Set1 Tab1(N,v);											
	Tab1.init(dx);
	//Tab1.printTab();

	Set2 Tab2(N, v);
	Tab2.init(dx);
	//Tab2.printTab();

	Set1 Tab1An(N,v);
	Tab1An.init(dx);
	Tab1An.analytical(dx, dt);
	//Tab1An.printTab();

	Set2 Tab2An(N,v);
	Tab2An.init(dx);
	Tab2An.analytical(dx, dt);
	//Tab2An.printTab();


	/******		Numerical Method selection by the User		*****/

	cout << "Choose one Numerical method (1,2,3 or 4):" << endl;
	cout << "1. Explicit FTBS" << endl;
	cout << "2. Implicit FTBS" << endl;
	cout << "3. Lax-Wendroff" << endl;
	cout << "4. Richtmyer" << endl;

	char choice;
	cin >> choice;
	switch (choice)
	{
		case '1':
			cout << "computing of Explicit FTBS" << endl;

			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Tab1.array[i][j + 1] = Tab1.eFTBS(Tab1.array[i][j], Tab1.array[i - 1][j]);
					Tab2.array[i][j + 1] = Tab2.eFTBS(Tab2.array[i][j], Tab2.array[i - 1][j]);
				}
			}
			if (N == 100) {
				myfile5.open("ExpFTBS100t5.dat");
				myfile10.open("ExpFTBS100t10.dat");
			}
			else if (N == 200) {
				myfile5.open("ExpFTBS200t5.dat");
				myfile10.open("ExpFTBS200t10.dat");
			}
			else if (N == 400) {
				myfile5.open("ExpFTBS400t5.dat");
				myfile10.open("ExpFTBS400t10.dat");
			}
			break;

		case '2':
			cout << "computing of Implicit FTBS" << endl;

			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Tab1.array[i][j + 1] = Tab1.iFTBS(Tab1.array[i][j], Tab1.array[i - 1][j+1]);
					Tab2.array[i][j + 1] = Tab2.iFTBS(Tab2.array[i][j], Tab2.array[i - 1][j+1]);
				}
			}
			if (N == 100) {
				myfile5.open("ImpFTBS100t5.dat");
				myfile10.open("ImpFTBS100t10.dat");
			}
			else if (N == 200) {
				myfile5.open("ImpFTBS200t5.dat");
				myfile10.open("ImpFTBS200t10.dat");
			}
			else if (N == 400) {
				myfile5.open("ImpFTBS400t5.dat");
				myfile10.open("ImpFTBS400t10.dat");
			}
			break;

		case '3':
			cout << "computing of Lax-Wendroff" << endl;
			
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Tab1.array[i][j + 1] = Tab1.LaxWendroff(Tab1.array[i][j], Tab1.array[i - 1][j], Tab1.array[i + 1][j]);
					Tab2.array[i][j + 1] = Tab2.LaxWendroff(Tab2.array[i][j], Tab2.array[i - 1][j], Tab2.array[i + 1][j]);
				}
			}
			if (N == 100) {
				myfile5.open("LaxWen100t5.dat");
				myfile10.open("LaxWen100t10.dat");
			}
			else if (N == 200) {
				myfile5.open("LaxWen200t5.dat");
				myfile10.open("LaxWen200t10.dat");
			}
			else if (N == 400) {
				myfile5.open("LaxWen400t5.dat");
				myfile10.open("LaxWen400t10.dat");
			}
			break;

		case '4':
			cout << "computing of Richtmyer" << endl;
			//double plus1, minus1;						//temporary local variable
			//Vector Step1Set1(static_cast<int>(N+1));
			//Vector Step1Set2(static_cast<int>(N+1));
			//Step1Set1[0] = 0;		//initial condition
			//Step1Set2[0] = 0;

			//Step1Set1[N] = 1;		//boundary condition
			//Step1Set2[N] = 0;

			//for (int i = 1; i < N ; i++) {
			//	for (int j = 0; j < N; j++) {

			//		for (int k = 1; k < N ; k++) {
			//		//We compute every i for each U(n+1/2). We redefine each loop j an entire new Vector defined on the index j
			//			Step1Set1[k] = Tab1.RichtmyerS1(Tab1.array[k + 1][j], Tab1.array[k - 1][j]);
			//			Step1Set2[k] = Tab2.RichtmyerS1(Tab2.array[k + 1][j], Tab2.array[k - 1][j]);
			//		}

			//		Tab1.array[i][j + 1] = Tab1.RichtmyerS2(Tab1.array[i][j], Step1Set1[i + 1], Step1Set1[i - 1]);
			//		Tab2.array[i][j + 1] = Tab2.RichtmyerS2(Tab2.array[i][j], Step1Set2[i + 1], Step1Set2[i - 1]);
			//	}
			//}
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Tab1.array[i][j + 1] = Tab1.Richtmyer(Tab1.array[i][j], Tab1.array[i + 1][j], Tab1.array[i - 1][j],u,dx,dt);
					Tab2.array[i][j + 1] = Tab2.Richtmyer(Tab2.array[i][j], Tab2.array[i + 1][j], Tab2.array[i - 1][j],u,dx,dt);
				}
			}
			if (N == 100) {
				myfile5.open("Richt100t5.dat");
				myfile10.open("Richt100t10.dat");
			}
			else if (N == 200) {
				myfile5.open("Richt200t5.dat");
				myfile10.open("Richt200t10.dat");
			}
			else if (N == 400) {
				myfile5.open("Richt400t5.dat");
				myfile10.open("Richt400t10.dat");
			}
			break;
	}

	/******		Print on the csv file	  *****/

	
	int j;
	int k;
	if (dt==0.5){j=10;k=20;}
	else if (dt==0.25){j=20;k=40;}
	else if (dt==0.1){j=50;k=100;}

	//template files  << "x" << "	" << "t" << "	" << "f1" << "	" << "f1A" << "	" << "f2" << "	" << "f2A" << endl;

	for (int i=0; i<=N ; i++)
	{
		myfile5 << -50 + i*dx << "	" << j*dt << "	" << Tab1.getElem(i,j-1) << "	" << Tab1An.getElem(i,j-1) << "	" << Tab2.getElem(i,j-1) << "	" << Tab2An.getElem(i,j-1) << endl;
		myfile10 << -50 + i*dx << "	" << k*dt << "	" << Tab1.getElem(i,k-1) << "	" << Tab1An.getElem(i,k-1) << "	" << Tab2.getElem(i,k-1) << "	" << Tab2An.getElem(i,k-1) << endl;
	}
	myfile5.close();
	myfile10.close();
	 

	return 0;
}
