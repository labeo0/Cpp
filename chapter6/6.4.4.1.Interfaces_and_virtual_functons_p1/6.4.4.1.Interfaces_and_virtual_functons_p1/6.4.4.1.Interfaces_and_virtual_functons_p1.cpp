// 6.4.4.1.Interfaces_and_virtual_functons_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};
class ExactValidator:public StringValidator
{
public:
	ExactValidator(string str):secret(str){}
	bool isValid(string str)
	{
		if(secret == str)
			return true;
		else
			return false;
	}
private:
	string secret;
};

class DummyValidator : public StringValidator {
public:
	virtual bool isValid(std::string input);
};
bool DummyValidator::isValid(std::string input)
{
	return true;
}
void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid\n" : "invalid\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact = ExactValidator("secret");
	printValid(exact, "hello");
	printValid(exact, "secret");
	return 0;
}

