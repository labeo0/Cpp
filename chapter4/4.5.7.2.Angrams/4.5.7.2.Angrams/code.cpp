//Are words anagrams?
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void toLow(string str)
{
	for(int i = 0; i < str.length()-1; i++)
	{
		tolower(str[i]);
	}
}
bool isAngram(string str1, string str2)
{
	if(str1.length() != str2.length())
		return 0;
	toLow(str1);//to lowwer letters
	toLow(str2);
	sort(str1.begin(),str1.end());//guess that is effective than comparing char by char in 2 word
	sort(str2.begin(),str2.end());
	if(str1 == str2)
		return 1;
	else
		return 0;
}
int main()
{
	string word1;
	getline(cin,word1);
	string word2;
	getline(cin,word2);

	if(isAngram(word1,word2))
		cout<<"Angram!!!\n";
	else
		cout<<"Not angram :(\n";

	system("pause");
	return 0;
}