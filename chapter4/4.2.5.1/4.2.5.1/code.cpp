//sum of numbers from 1 to N (ariphmetic progression)
#include <iostream>

using namespace std;
int main()
{
	long long int N = 0;
	cout<<"Enter N\n";
	cin >> N;
	N = (N+1)*N/2;
	cout <<N<<endl;
	system("pause");
	return 0;
}