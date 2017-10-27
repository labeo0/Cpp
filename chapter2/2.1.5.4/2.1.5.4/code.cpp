//Find day of the week using date (Zellar congruence)
#include <iostream>
#include <string>
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
int daysInMonth(int month, int year)
{
	int days [13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap(year) && month == 2)
		return days[0];
	return days[month];
}
int main()
{
	int year,month,day,num;
	string weekday [7] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	cout << "Enter date 20-21th century\n";
	do{
		cout << "Year: ";
		cin >> year;
	}while(year<1900 || year >=2100);

	do{
		cout << "Month: ";
		cin >> month;
	}while(month<1 || month >12);
	do{
		cout << "Day: ";
		cin >> day;
	}while(day < 1 || day > daysInMonth(month,year));
	cout <<year<<'.'<<month<<'.'<<day<<" is ";
	
	if(month-2 <= 0)
	{
		month+=12;
		year--;
	}
	/*num = ( month*83/32 +day + year +year/4 - year/100 +year/400)%7;
	meh, this doesn`t work
	*/

	//this is from wiki
	int k = year%100;
	int j = year/100;
	num =(day + 13*(month+1)/5 +  k + k/4 + j/4 + 5*j)%7;

	cout << weekday[num]<<endl;
	system("pause");
	return 0;
}