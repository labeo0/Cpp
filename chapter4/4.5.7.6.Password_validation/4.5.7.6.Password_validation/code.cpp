#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool isValid(string str)
{
	string message = "";
	if(str.length()<8)
	{
		message+="The password must be 8 characters long\n";
		return 0;
	}

	int upCount = 0, lowCount = 0, digCount = 0, specCount = 0;
	for(int i = 0; i < str.length()-1; i++)
	{
		if(islower(str[i]))
			lowCount++;
		else if(isupper(str[i]))
			upCount++;
		else if(isdigit(str[i]))
			digCount++;
		else
			specCount++;
	}
	if(upCount&&lowCount&&digCount&&specCount)
		return 1;
	if(!upCount)
		message+="The password must have at least one upper case letter\n";
	if(!lowCount)
		message+="The password must have at least one lower case letter\n";
	if(!digCount)
		message+="The password must have at least one digit\n";
	if(!specCount)
		message+="The password must have at least one special symbol\n";
	std::cout<<message;
	return 0;
}

int main(){
	string pass = "aswrdsdfP1@sef";
	//getline(cin,pass);

	if(isValid(pass))
		cout<<"Password is valid\n";

	system("pause");
	return 0;
}