//text manipilating remobe duplicate white spaces
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string text;
	
	cout<<"Enter text\n";
	getline(cin,text);
	int hasDuplicate = text.find("  ");

	while(hasDuplicate!=string::npos)
	{
		text.replace(hasDuplicate,2," ");
		hasDuplicate = text.find("  ");
	}
	cout<<text<<endl;

	system("pause");
	return 0;
}