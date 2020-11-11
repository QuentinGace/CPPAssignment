// Assignment CPP Gr3
// Quentin Parmeshwari Luc

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int n;									// number of points
	int u = 1.75;							// speed sound u = 1.75 m/s 
	int dt = 0.5;							// time time depending on CFL conditions

	cout << "Enter the number of point we would take between [-50,50] :" << endl;
	cin >> n;								
	int dx = 100 / n;						// the step
	return 0;
}
