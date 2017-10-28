//Solve a riddle
#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "Enter size of the side (only odd numbers >1)\n";
	do{
		cin >> a;
		if(a < 3 && a%2 != 0)
			cout << "oops\nTry again\n";
		else
			cout << "Ok, sloving the riidle\n";
	}while(a < 3 && a%2 != 0);
	//base formula (2a-1)+( (a-2)^2 - 1 )
	cout <<"Bottom right corner of square with side " <<a<<" is: " <<2*a + (a-2)*(a-2) -2<<endl;
	system("pause");
	return 0 ;
}