//Find aprox vallue of pi
#include <iostream>

using namespace std;

int main(void) {
	double pi4 = 0.;
	long n;
	cout << "Number of iterations? ";
	cin >> n;

	double num = 1.;
	for(int i = 0; i < n;i++)
	{
		pi4 += 1./num - 1./(num+2.);
		num+=4;
	}


	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;

	system("pause");
	return 0;
}