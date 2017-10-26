//Lab 1.4.1 Floats: operators and expressions
#include <iostream>
using namespace std;
int main(void) {
	float pi = 3.14159265359;
	float x,y;
	cout << "Enter value for x: ";
	cin >> x;
	
	float p1,p2;
	p1 = x*x/(pi*pi)/(x*x+.5);
	p2 = 1. + (x*x/(pi*pi)/(x*x-.5)/(x*x-.5));

	y=p1*p2;
	cout << "y = " << y;
	system("pause");
	return 0;
}
