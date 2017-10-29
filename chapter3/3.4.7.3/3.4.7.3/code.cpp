#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};
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
int dayOfYear(Date date) {
	int res = 0;
	for(int i = 1; i < date.month; i++)
		res+=monthLength(date.year,i);

	return res + date.day;
}

int main(void) {
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	system("pause");
	return 0;
}