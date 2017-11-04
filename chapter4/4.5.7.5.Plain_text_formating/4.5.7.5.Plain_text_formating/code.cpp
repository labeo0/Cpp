#include <string>
#include <iostream>
int main()
{
	std::string sentence;
	std::getline(std::cin, sentence);

	// manipulate the sentence here
	std::cout << sentence << "\n";
	
	system("pause");
	return 0;
}