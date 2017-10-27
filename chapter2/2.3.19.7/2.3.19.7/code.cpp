//: Fibonacci sequence
#include <iostream>

using namespace std;

int main()
{
	unsigned long pre = 1, now = 1, temp;
	unsigned short n;
	cout << "Enter n for n-th Fibonacci number\nFirst and second numbers equals to 1\nSo n>2\n";
	do{
		cin >> n;
	}while(n<3);

	for(int i = 0; i < n -2; i++)
	{
		temp = now;
		now+=pre;
		pre=temp;
	}
	cout <<n<<"-th Fibonacci number: "<< now<<endl;

	system("pause");
	return 0;
}