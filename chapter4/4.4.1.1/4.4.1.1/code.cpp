#include <iostream>
#include <string>

using namespace std;
bool isPangram(int *ptr, int size)
{	
	for(int i = 0; i < size;i++)
	{
		if(*ptr+i == 0)//чисто для разнообразия
			return 0;
	}
	return 1;
}
int main()
{

	int vec[26] = {0};//a =[0],z=[25]
	//letter a = 97, A = 97 -32
	int * ptr = vec;
	int size = sizeof vec / sizeof *ptr;

	string text;
	cout << "Enter text\n";
	getline(cin,text);
	for(int i = 0; i < text.length(); i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(text[i]==97+j || text[i]==65+j)//Count capital and small letters
				vec[j]++;
		}
	}

	for(int i = 0; i<26; i++)
	{
		cout<<char(97+i)<<"-"<<vec[i]<<endl;
	}

	(isPangram(ptr,size))?cout<<"It s Pangram!\n": cout<<"It is not Pangram :(\n";
	

	system("pause");
	return 0;
}