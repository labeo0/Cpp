#include <iostream>

using namespace std;

int main(void) {
	double matrix[][4] = { 
	{ 1, 2, 3, 0 },
	{ 2, 2, 3, 1 },
	{ 3, 3, 3, 2 },
	{ 0, 1, 2, 4 } };
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	bool issymmetric = true;
	
	int i = 0;
	while(issymmetric && i < side)
	{
		for(int j = 0; j < side; j++)
			if(matrix[i][j]!=matrix[j][i])
				issymmetric = false;
		i++;
	}

	if(issymmetric)
		cout << "The matrix is symmetric" << endl;
	else
		cout << "The matrix is not symmetric" << endl;

	system("pause");
	return 0;
}