#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	struct Time{
		int hours;
		int minutes;
	};
	Time start = {};
	Time finish = {};
	Time res= {};
	cout<<"Enter start time\nHours: \n";
	do{
		cin >> start.hours;
	}while(start.hours <0 || start.hours >=24);
	cout<<"\nMinutes: \n";
	do{
		cin >> start.minutes;
	}while(start.minutes <0 || start.minutes >=60);

	cout<<"Enter finish time, must be later time of the same day\nHours: \n";
	do{
		cin >> finish.hours;
	}while(finish.hours <0 || finish.hours >=24 || finish.hours < start.hours);
	cout<<"\nMinutes: \n";
	do{
		cin >> finish.minutes;
	}while(finish.minutes <0 || finish.minutes >=60|| (finish.hours == start.hours && finish.minutes < start.minutes)   );

	res.hours = finish.hours - start.hours;
	res.minutes = finish.minutes - start.minutes;
	if(res.minutes < 0)
	{
		res.hours--;
		res.minutes+=60;
	}
	cout <<res.hours<<':'<<res.minutes<<endl;
	

	system("pause");
	return 0;
}