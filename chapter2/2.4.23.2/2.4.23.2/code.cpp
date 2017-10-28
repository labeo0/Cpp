#include <iostream>

using namespace std;

bool isPalindrome(unsigned short int val)
{
	//will check if the bit from the right equals the to the left.
	//then move inside
	
	int r = 0, l = 31;
	for(int i = 0; i <= 31; i++)
	{
		if( (val<<r &1) != (val<<l &1) )// << higher priority than &
			return false;
		r++;l--;
	}
	return true;
}
int main(void) {
	unsigned short int val;
	cout << "value = ";
	cin >> val;

	if(isPalindrome(val))
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;
	system("pause");
	return 0;
}