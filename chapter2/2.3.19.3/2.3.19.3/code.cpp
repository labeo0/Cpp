//Power of 2 positive
#include <iostream>

using namespace std;

int main()
{
	unsigned _int64 num = 1;// unsigned long long or double also works
	unsigned short p;
	cout <<"Enter desired power of 2 <64 and >0 \n";
	cin >> p;
	for(int i = 0; i < p; i++)
		num*=2;
	cout<< "Result: "<< num << endl;

	system("pause");
	return 0;
}