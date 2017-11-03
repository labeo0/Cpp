//replace one string with another in the sentrnce/ no problems with similar strings
#include <string>
#include <iostream>
using namespace std;

int main()
{
	std::string from;
	std::getline(std::cin, from);
	std::string to;
	std::getline(std::cin, to);
	std::string sentence;
	std::getline(std::cin, sentence);

	int startLook = sentence.find(from);
	bool isReplaced;
	do{
		isReplaced = false;
		if(startLook!=string::npos)
		{
			sentence.replace(startLook,from.length(),to);
			startLook=sentence.find(from,startLook+1);
			isReplaced = true;
		}
	}while(isReplaced);

	std::cout << sentence << "\n";
	system("pause");
	return 0;
}