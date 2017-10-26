#include <iostream>
#include <iomanip>

using namespace std;

int main(void) 
{
		float i = 2.3;
		float q = 2.3;
		float w = 2.123456;
		float e = 2.123456;
		float p = 2.123456;

		cout << setprecision(1) << fixed << i << endl;
		cout << setprecision(2) <<q << endl;
		cout << setprecision(6) << w << endl;
		cout << setprecision(2) << e << endl;
		cout <<  (int)p << endl;

		system("pause");
	return 0;
}