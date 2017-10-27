//Find Easter Day using year
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,year;
	cout << "Enter year 20-21th century\n";
	do{
		cout << "Year: ";
		cin >> year;
	}while(year<1900 || year >=2100);
	a = year%19;
	b = year%4;
	c = year%7;
	d = (a*19 + 24)%30;
	e = (2*b + 4*c + 6*d + 5)%7;
	if(e+d < 10)
		cout << "Easter on " <<d+e+22 << " of March\n";
	else 
		cout << "Easter on " <<d+e-9 << " of April\n";

	system("pause");
	return 0;
}