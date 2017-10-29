#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void) {
	int maxball;
	int ballsno;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));
	int *vec = new int [ballsno];
	int temp; bool used;
	for(int i = 0 ; i < ballsno; i++)
	{
		
		temp = rand()%maxball +1;
		
	}
	
	system("pause");
	return 0;
}