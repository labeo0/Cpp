//Atm driver??? minimal amount of banknotes 50 20 10 5 1

#include <iostream>

using namespace std;


int main()
{
	int cash;
	int banknotes[5] ={50,20,10,5,1};
	cout <<"Enter amount of money you want\n";
	cin >> cash;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j<cash/banknotes[i];j++)
		{
			cout <<banknotes[i] <<' ';
		}
		cash-=cash/banknotes[i]*banknotes[i];
	}
	cout << endl;
	system("pause");
	return 0;
}