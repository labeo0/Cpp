// 5.3.10.5.Modeling_frations_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Fraction{
public:
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	string toString()
	{
		string res = "";
		char *str = new char[];
		if(numerator*denominator < 0)
		{
			res+='-';
			numerator = abs(numerator);
			denominator= abs(denominator);
		}
		else if(numerator*denominator>0)
		{
			numerator = abs(numerator);
			denominator= abs(denominator);
		}
		else
			return "0";

		int integer = numerator/denominator;

		if (integer == 0)
		{
			_itoa(numerator,str,10);
			res+=string(str)+'/';
			_itoa(denominator,str,10);
			res+=string(str);
		}
		else if(integer > 0 && numerator%denominator == 0)
		{
			_itoa(numerator/denominator,str,10);
			res+=string(str);
		}
		else if(integer > 0&& numerator%denominator!=0)
		{
			_itoa(integer,str,10);
			res+= string(str)+" ";
			_itoa(numerator-integer*denominator,str,10);
			res+=string(str)+"/";
			_itoa(numerator-integer*denominator,str,10);
		}

		return res;
	}
	double toDouble()
	{
		return double(numerator)/denominator;
	}
private:
	int numerator;
	int denominator;
};

int _tmain(int argc, _TCHAR* argv[])
{
	int num, den;
	bool denIsZero = true;
	do{
		std::string input = "-16/-32";
		//std::getline(std::cin,input);
		num = std::stoi(input.substr(0,input.find("/")));
		den = std::stoi(input.substr(input.find("/")+1,std::string::npos));
		if(den == 0)
			std::cout<<"Cant divide by zero!\nTry again\n";
		else
			denIsZero = false;
	}while(denIsZero);

	Fraction fraction(num, den);
	std::cout << fraction.toString() << " is " << fraction.toDouble()<<" in decimal\n";
	return 0;
}

