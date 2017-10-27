#include <iostream>
using namespace std;
int main(void) {
	int year;
	cout << "Enter a year: ";
	cin >> year;
	if(year > 1582)//gregorian calendar starts from 1582
	{
		if(year%4 != 0)
			cout << "Common year \n";
		else if(year%100 !=0)
			cout << "Leap Year \n";
		else if(year%400 != 0)
			cout << "Common year \n";
		else
			cout << "Leap Year \n";
	}
	else
		cout << "Out of Gregorian era \n \a";
		system("pause");
	return 0;
}
