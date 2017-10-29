#include <iostream>

using namespace std;

bool isLeap(int year) {
	if(year%4 != 0)
		return 0;
	else if(year%100 !=0)
		return 1;
	else if(year%400 != 0)
		return 0;
	else
		return 1;
}
int main(void) {
	for(int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;

	system("pause");
	return 0;
}