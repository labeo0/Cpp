//Number of 1bits in integer
#include <iostream>

using namespace std;

int main()
{
	unsigned long num;
	int count = 0;
	cout <<"Enter positive number\n";
	cin >> num;
	for(int i = 0; i < 32; i++)
	{
		if((num&1) == 1)
		{
			count++;
			num = num >> 1;
		}
		else
		num = num >> 1;
	}
	cout <<"Numer of 1 is: "<<count<<endl;


	system("pause");
	return 0;
}