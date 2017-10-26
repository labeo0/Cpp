#include <iostream>
#include <iomanip>

using namespace std;

int main(void) 
{
	int one, two, three, four;

	do{
		cout << "Enter first octet from 0 to 255 \n";
		cin >> one;
	}while(one < 0 || one > 255);

	do{
		cout << "Enter second octet from 0 to 255  \n";
		cin >> two;
	}while(two < 0 || two > 255);

	do{
		cout << "Enter third octet from 0 to 255  \n";
		cin >> three;
	}while(three < 0 || three > 255);

	do{
		cout << "Enter fourth octet from 0 to 255  \n";
		cin >> four;
	}while(four < 0 || four > 255);

	cout << one <<'.'<<two<<'.'<<three<<'.'<<four <<endl;
	system("pause");
	return 0;
}