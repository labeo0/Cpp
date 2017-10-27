#include <iostream>
using namespace std;
int main(void) {
	int n;
	cout << "Enter the size of rectangle must be >1 and <20\n";
	do{
		cin >> n;
		if(n<=1 || n > 20)
			cout << "Sorry, you are out of range\nTry again\n";
		else 
			cout << "Ok, start drawing\n";

	}while(n<=1 || n > 20);

	cout << '+';
	for(int i = 0; i < n; i++)
		cout << '-';
	cout << '+' << endl;
	for(int i = 0; i < n; i++) {
		cout << '|';
		for(int j = 0; j < n; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	for(int i = 0; i < n; i++)
		cout << '-';
	cout << '+' << endl;
	system("pause");
	return 0;
}