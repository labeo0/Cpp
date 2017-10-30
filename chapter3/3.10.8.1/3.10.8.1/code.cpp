#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//recurtion doesnt work(sometimes works)
/*
void draw(int maxball,int ballsno, int *vec, int step = 0)
{
	vec[step] = rand()%maxball + 1;
	for(int i = 0; i < step; i++)
	{
		if(vec[step]==vec[i] )
			draw(maxball, ballsno, vec, step);
	}
	if(step < ballsno)
		draw(maxball, ballsno, vec, step + 1);
}*/
bool contain(int num,int step, int *vec)
{
	for(int i = 0; i < step; i++)
	{
		if(vec[i] == num && i!=step)
			return 1;
	}
	return 0;
}
int main(void) {
	int maxball;
	int ballsno;
	cout << "Max ball number? \n";
	cin >> maxball;
	cout << "How many balls? \n";
	cin >> ballsno;
	srand(time(NULL));
	int temp;
	int *vec = new int [ballsno];
	for(int i = 0; i < ballsno; i++)
	{
		temp = rand()%maxball + 1;
		if(contain(temp, i, vec))
		{
			i--;
			continue;
		}
		vec[i] = temp;
	}
	
	for(int i = 0 ; i< ballsno; i++)
		cout<<vec[i]<<" ";
	delete[] vec;
	system("pause");
	return 0;
}