#include <iostream>
using namespace std;
int main(void) {
	bool answer;
	int v;
	cout << "Enter a value: ";
	cin >> v;
	answer = (v >= 0 && v < 10)||(v*2 < 20 && v-2 > -2)||(v-1 > 1 && v/2 < 10)||v==111 ;
		cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
		system("pause");
	return 0;
}