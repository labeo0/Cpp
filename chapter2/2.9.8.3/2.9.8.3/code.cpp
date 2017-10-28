//Palindrome in vector
#include <iostream>

using namespace std;

int main(void) {
	int vector[] = {-1, 7, 3, 8, 9, 8, 3, 7, -1};
	bool ispalindrome = true;
	int n = sizeof(vector) / sizeof(vector[0]);
	
	int i = 0;
	//dont like break, so no for()
	while(i < n/2 && ispalindrome)// n/2 to avoid double check
	{
		if(vector[i] !=vector[n-i-1])// last index is n-1
			ispalindrome = false;
		i++;
	}

	if(ispalindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;
	system("pause");
	return 0;}