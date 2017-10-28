#include <iostream>

using namespace std;

int main()
{
	int add;
	struct Time{
		int hours;
		int minutes;
	};
	Time time1 = {};
	cout<<"Enter time\nHours: \n";
	do{
	cin >> time1.hours;
	}while(time1.hours <0 || time1.hours >=24);
	cout<<"Enter time\nMinutes: \n";
	do{
	cin >> time1.minutes;
	}while(time1.minutes <0 || time1.minutes >=60);

	cout <<"Enter minnutes you want to add\n";
	cin >> add;

	int temp = time1.minutes+add;
	time1.minutes = (temp)%60;
	time1.hours = (time1.hours + temp/60)%24;
	cout <<time1.hours<<':'<<time1.minutes;

	system("pause");
	return 0;
}