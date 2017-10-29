#include <iostream>

using namespace std;

bool isLeap(int year)
{
	//Common year  = 0 ; Leap = 1 
	if(year%4 != 0)
		return 0;
	else if(year%100 !=0)
		return 1;
	else if(year%400 != 0)
		return 0;
	else
		return 1;	
}
int monthLength(int year, int month)
{
	int days [13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap(year) && month == 2)
		return days[0];
	return days[month];
}
int main(void) {
	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr,mo) << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}