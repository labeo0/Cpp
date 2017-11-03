#include <string>
#include <iostream>

using namespace std;
void dupSpaces(string &text)
{
	int hasDuplicate = text.find("  ");
	while(hasDuplicate!=string::npos)
	{
		text.replace(hasDuplicate,2," ");
		hasDuplicate = text.find("  ");
	}
	
}
int main()
{
	string text;
	getline(cin, text);
	string temp;

	
	cout << text << "\n";

	system("pause");
	return 0;
}