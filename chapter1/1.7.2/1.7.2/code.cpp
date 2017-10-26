#include <iostream>
#include <iomanip>

using namespace std;

int main(void) 
{
		int i,j;		
		cout << "Enter first int \n";
		cin >> i;
		cout << "Enter second num \n";
		cin >> j;
		if(1./(float)i == 1./(float)j){
			cout << "equal \n";
		}
		else cout << "not equal \n";
		system("pause");
	return 0;
}