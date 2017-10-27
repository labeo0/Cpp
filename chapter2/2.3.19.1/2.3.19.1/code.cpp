//Check Collatz's hypothesis for defenite number
#include <iostream>


using namespace std;
int main()
{
	unsigned int c0,count = 0;
	cout << "Enter non-zero & non-negative number\n";
	cin >> c0;
	while(c0 != 1)
	{
		if(!(c0%2))
			c0/=2;
		else c0= c0*3+1;
		count++;
		cout << c0<<endl;
	}
	cout <<"Steps: "<<count<<endl;
	system("pause");
	return 0;
}