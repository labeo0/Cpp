// 5.3.10.6.Modelling_fractions_p2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
class Fraction{
public:
	Fraction(int numerator, int denominator)
	{
		int gcd = euclidean(numerator,denominator);
		this->numerator = numerator/gcd;
		this->denominator = denominator/gcd;
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
	// the functions below do not change the object
	// on which they are called, they produce a new object
	Fraction plus(Fraction that)
	{
		int num = numerator*that.denominator + that.numerator*denominator;
		int den = denominator*that.denominator;
		Fraction res(num,den);
		//res.reduce();
		return res;
	}
	Fraction minus(Fraction that)
	{
		int num = numerator*that.denominator - that.numerator*denominator;
		int den = denominator*that.denominator;
		Fraction res(num,den);
		//res.reduce();
		return res;

	}
	Fraction times(Fraction that)
	{
		int num = this->numerator * that.numerator;
		int den = this->denominator * that.denominator;
		Fraction result(num, den);
		return result;
	}
	Fraction by(Fraction that)
	{
		int num = this->numerator * that.denominator;
		int den = this->denominator * that.numerator;
		Fraction result(num, den);
		//res.reduce();
		return result;
	}
private:
	int numerator;
	int denominator;
	int euclidean(int b, int a)
	{
		//find greatest common devisor
		if(b>a)
			swap(b,a);

		int temp;
		while(b != 0)
		{
			temp = b;
			b = a%temp;
			a = temp;
		}
		return a;
	}
	void reduce()
	{
		//greatest common divisor
		int gcd = euclidean(numerator,denominator);
		numerator/=gcd;
		denominator/=gcd;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Fraction f1(7,4);
	Fraction f2(-6,10);

	Fraction result = f1.plus(f2);
	cout << result.toString()<<endl;

	result = f1.minus(f2);
	cout << result.toString()<<endl;

	result = f1.times(f2);
	cout << result.toString()<<endl;

	result = f1.by(f2);
	cout << result.toString()<<endl;

	return 0;
}

