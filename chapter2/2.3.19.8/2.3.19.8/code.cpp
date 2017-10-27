//n-th factorial
#include <iostream>

using namespace std;

int main()
{
	unsigned short n;
	unsigned long res = 1;
	cout << "Enter n to find factorial (non-negative)\n";
	do{
		cin >> n;
	}while(n<0);

	while(n>=1)
	{
		res*=n;
		n--;
	}
	cout <<n <<" factorial: "<< res <<endl;

	system("pause");
	return 0;
}