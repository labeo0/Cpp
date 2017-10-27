//Draw Geeza Piramids
//meh, this will take some time
//hz, if it is ok

#include <iostream>

using namespace std;
void spaces(int num)
{
	for(int i = 0; i < num; i++)
		cout << " ";
}
void stars(int h)
{
	for(int j = 1; j <= 2*h-1; j++)
				cout << '*';
}

int main()
{
	int h, insp = 1;//insp = spaces inside the piramids
	int t = 1;//mmm, making kostili feels good. Use for making spaces beetwen piramids
	cout << "Alright, just doit.\n Enter the height of piramids\n  >2 and <9\n";
	do{
		cin >> h;
		if(h<3 || h>8)
			cout << "oops, out of range\nTry again\n";
		else 
			cout << "ok, start drawing\n";
	}while(h<3 || h>8);

	for(int i = 1; i <=h; i++)
	{
		//divide drawing in 3 parts
		if(i==1)//top part
		{
			spaces(h-i);
			cout << '*';
			spaces(2*h-i);
			cout << '*';
			spaces(2*h-i);
			cout << '*';
			spaces(h-i);
			cout << endl;
		}
		else if(i==h){//bottom part
			stars(h);
			cout<<' ';
			stars(h);
			cout<<' ';
			stars(h);
		}
		else//and middle
		{
			spaces(h-i);

			cout << '*';
			spaces(insp);
			cout << '*';

			spaces(2*h-i-t);

			cout << '*';
			spaces(insp);
			cout << '*';

			spaces(2*h-i-t);

			cout << '*';
			spaces(insp);
			cout << '*';
			
			spaces(h-i);
			cout << endl;
			insp+=2;
			t+=1;
		}

	}
	cout << endl;
	system("pause");
		return 0;
}