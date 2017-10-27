
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void) {
	int sys;
	float m, ft, in ;


	cout << "Which measurment system do you prefer?\n";
	do{
		cout << "0-metric\n1-imperial\n";
		cin >> sys;	
	}while( (sys!=0 || sys==1)&&(sys == 0 || sys !=1) );
	if(sys == 0)
	{
		cout <<"Enter distance\n";
		cout << "Meters: ";
		cin >> m;
		m=abs(m);

		ft = (int)(m*39.37 / 12);
		in = fmod(m*39.37 , 12.);
		cout << fixed << setprecision(5) << ft << "\'" << in <<"\"";
	}
	if(sys == 1)
	{
		cout <<"Enter distance\n";
		cout << "Feet: ";
		cin >> ft;	
		cout << "Inches: ";
		cin >> in;
		ft = abs(ft); in = abs(ft);
		m = (ft*12.+in)/39.37;
		cout << fixed << setprecision(5) << m <<"m ";
	}
	system("pause");
	return 0;
}
