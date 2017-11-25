// 6.3.7.1.Polymorphism_p3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class IPAddress
{
public:
	IPAddress():ip(""){}
	IPAddress(string ip):ip(ip){}
	IPAddress(IPAddress &address):ip(address.ip){}
	virtual void print()
	{
		cout<<ip<<endl;
	}
	string getIp(){return ip;}
protected:
	bool IsDigitDot()
	{
		string ip = this->ip;
		for(int i = 0; i < ip.length(); i++)
		{
			if(ip[i]!='.' && !isdigit(ip[i]))
				return 0;
		}
		return 1;
	}
	bool hasFourParts()
	{
		string ip = this->ip;
		int count = 0;
		for(int i = 0; i < ip.length(); i++)
			if(ip[i]=='.')
				count++;

		return count ==  3 ? 1:  0;
	}
	bool validParts()//can use if has 4 parts
	{
		string ip = this->ip;
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
	bool validPartsValue()//take part of ip and check it/ '.' delimiter
	{
		string ip = this->ip;
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
	string ip;
};
class IPAddressChecked : public IPAddress
{
public:
	IPAddressChecked():IPAddress(),correct(false){}
	IPAddressChecked(string address):IPAddress(address)
	{
		correct = IsDigitDot()&&hasFourParts()&&validParts()&&validPartsValue();
	}
	IPAddressChecked(IPAddress & ipadd)
	{
		this->ip = ipadd.getIp();
		correct = IsDigitDot()&&hasFourParts()&&validParts()&&validPartsValue();
	}
	void print()
	{
		if(correct)
			cout<<ip<<" Correct\n";
		else
			cout<<ip<<" Not corrext\n";
	}
private:
	bool correct;
};

int _tmain(int argc, _TCHAR* argv[])
{
	IPAddress add1 = IPAddress("192.169.0.1");
	add1.print();
	IPAddress add2 = IPAddress("999.29.29.29");
	add2.print();

	IPAddressChecked add3 = IPAddressChecked(add2);
	add3.print();
	IPAddressChecked add4 = IPAddressChecked("199.29.29.29");
	add4.print();
	return 0;
}

