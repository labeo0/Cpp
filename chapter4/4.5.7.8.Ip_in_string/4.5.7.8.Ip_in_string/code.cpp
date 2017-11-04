#include <iostream>
#include <string>
using namespace std;

bool IsDigitDot(string ip)
{
	for(int i = 0; i < ip.length(); i++)
	{
		if(ip[i]!='.' && !isdigit(ip[i]))
			return 0;
	}
	return 1;
}
bool hasFourParts(string ip)
{
	int count = 0;
	for(int i = 0; i < ip.length(); i++)
		if(ip[i]=='.')
			count++;

	return count ==  3 ? 1:  0;
}
bool validParts(string ip)//can use if has 4 parts
{
	int count [4] = {0};
	int j = 0;
	for(int i = 0; i < ip.length(); i++)
	{
		if(ip[i]=='.')
			j++;
		else
			count[j]++;
	}
	j = 0;
	while(j<4)
	{
		if(count[j]>3 || count[j] <=0)
			return 0;
		j++;
	}
	return 1;
}
bool validPartsValue(string ip)//take part of ip and check it/ '.' delimiter
{
	string part;
	int check = ip.find('.');
	ip+=".";//last part of ip will be checked in this case

	do{
		part = ip.substr(0,check);
		ip = ip.substr(check+1,string::npos);
		if(stoi(part)>255 || stoi(part)<0)
			return 0;
		check = ip.find('.');
	}while(check!=string::npos);
	return 1;
}
bool isValid(string ip)
{
	if(!IsDigitDot(ip))
	{
		cout<<"Only digits and dots allowed\n";
		return 0;
	}
	if(!hasFourParts(ip))
	{
		cout <<"Incorrect parts count\n";
		return 0;
	}
	if(!validParts(ip))
	{
		cout<<"Too many characters in a part\n";
		return 0;
	}
	if(!validPartsValue(ip))
	{
		cout<<"Too big a value of a part\n";
		return 0;
	}
	return 1;
}
int main()
{
	std::string ip = "22.300.205.250";
	std::getline(std::cin,ip);

	if(isValid(ip))
		cout<<"IP is valid\n";
	system("pause");
	return 0;
}