// 5.3.10.5.Modeling_frations_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
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
		if(numerator == 0)
			return 0;
		stringstream res;
		int num = abs(numerator);
		int den = abs(denominator);

		//find if fraction is negative
		if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
			res<<"-";

		if(double(num)/den == 1)
		{
			res<<'1';
			return res.str();
		}
		else if(num>den)
		{
			int intg = num/den;//integer part
			num-=intg*den;

			res<<intg<<' '<<num<<'/'<<den;
			return res.str();
		}
		res<<' '<<num<<'/'<<den;
		return res.str();

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

