#include <iostream>

using namespace std;

int main(void) {
	int matrix[10][10] = { };
	int *p = &matrix[0][0];

	for(int i = 1; i < 11; i++)
	{
		for(int j = i; j < i*11; j+=i)
		{
			*p = j;
			p++;
		}
	}

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}