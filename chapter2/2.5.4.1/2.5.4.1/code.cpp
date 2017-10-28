//ITS CALCULATORRRR!!!!!1111!!1111
#include <iostream>

using namespace std;

int main()
{
	int opt = -1;
	double v1,v2;
	while(opt != 0)
	{
		cout <<"MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice?\n";
		cin >> opt;
		switch (opt)
		{
		case 0 :return 0;
		case 1:{
			cout << "v1+v2\nEnter v1\n";
			cin >> v1;
			cout << "Enter v2\n";
			cin >> v2;
			cout <<"Result: "<<v1<<" + "<<v2<<" = "<<v1+v2<<endl;
			   }break;
		case 2:{
			cout << "v1-v2\nEnter v1\n";
			cin >> v1;
			cout << "Enter v2\n";
			cin >> v2;
			cout <<"Result: "<<v1<<" - "<<v2<<" = "<<v1-v2<<endl;
			   }break;
		case 3:{
			cout << "v1*v2\nEnter v1\n";
			cin >> v1;
			cout << "Enter v2\n";
			cin >> v2;
			cout <<"Result: "<<v1<<" * "<<v2<<" = "<<v1*v2<<endl;
			   }break;
		case 4:{
			cout << "v1/v2\nEnter v1\n";
			cin >> v1;
			cout << "Enter v2\n";
			cin >> v2;
			if(v2 == 0)
			{cout<<"Ti sho,dyadya? No division by 0 on my watch\n";break;}

			cout <<"Result: "<<v1<<" / "<<v2<<" = "<<v1/v2<<endl;
			   }break;
		default: cout <<"Ooops, try again\n";
			break;
		}
	}
	system("pause");
	return 0;
}