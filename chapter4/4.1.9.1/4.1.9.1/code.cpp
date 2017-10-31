//dinamic matrix from pointers for students grades
#include <iostream>
#include <iomanip>
using namespace std;
int Check(int num)
{
	if(num > 5)
		return 5;
	else if(num < 1)
		return 1;
	return num;
}
int main()
{
	int courseNum;
	int **arr;
	float courseSum = 0, overFin = 0; 
	cout << "Enter number of courses\n";
	cin >> courseNum;

	arr = new int * [courseNum];
	cout<<"Enter grades from 1 to 5.\nFirst number is amount of grades for course"<<endl;
	for (int r = 0; r < courseNum; r++) {
		arr[r] = new int[r + 1];
		cin >> arr[r][0];
		for(int c = 1; c <= arr[r][0]; c++)
		{
			cin >> arr[r][c];
			arr[r][c] = Check(arr[r][c]);//check if grades are in range 1-5
		}
	}
	for(int i = 0; i < courseNum; i++)
	{
		for(int j = 1; j <= arr[i][0]; j++)
		{
			courseSum+=arr[i][j];
		}
		cout <<fixed<<setprecision(2)<<"Course "<<i+1<<": final "<<courseSum/arr[i][0]<<" grades :";
		for(int c = 1; c <= arr[i][0]; c++)
			cout << arr[i][c] << " ";

		cout << endl;
		overFin+=courseSum/arr[i][0];
		courseSum = 0;
	}
	cout<<"Overall final: "<<  overFin/courseNum <<endl;
	cout <<endl;

	system("pause");
	return 0 ;
}