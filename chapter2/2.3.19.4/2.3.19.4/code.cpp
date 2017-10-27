//Power of 2 negative
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double num = 1;// unsigned long long or double also works
	unsigned short p;
	cout <<"Enter desired power of 2 <64 and >0 \n";
	cin >> p;
	for(int i = 0; i < p; i++)
		num/=2;
	cout<<fixed<<setprecision(20)<< "Result: "<< num << endl;

	system("pause");
	return 0;
}