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

int daysBetween(Date d1, Date d2) {
	int aux, res = 0;
	if(d2.year == d1.year)
	{
		aux = dayOfYear(d2)- dayOfYear(d1);
		return (aux > 0)? aux: -1;
	}
	else if (d2.year > d1.year)
	{
		for(int i = d1.year; i < d2.year; i++)
		{
			isLeap(i)? res+=366 : res+=365 ;
			
		}
		
		return res - dayOfYear(d1) + dayOfYear(d2);
	}
	else
		return -1;
}
int main(void) {
	Date since,to;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> to.year >> to.month >> to.day;
	cout << daysBetween(since,to) << endl;

	system("pause");
	return 0;
}
