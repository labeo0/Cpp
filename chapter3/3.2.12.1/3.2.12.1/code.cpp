// find min value in vector using  pointers (no index)
#include <iostream>

using namespace std;

int main(void) {
	int vector[] = { 3, -5, 7, 10, -4, -15, -15, -15, -20 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *p1 = vector, *p2 = p1+1;
	for(int i = 1; i < n; i++)
	{
		if(*p1 < *p2)
			p2++;
		else {
			p1 = p2;
			p2++;
		}
	}
	cout << *p1;
		/*int min = 1000;
		for(int i = 0; i < n; i++)
		{
		if(*p1 < min)
		min = *p1;
		p1++;
		}
		cout <<min<<endl;*/
		system("pause");
	return 0;
}