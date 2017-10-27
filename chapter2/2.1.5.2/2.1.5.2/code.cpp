#include <iostream>
using namespace std;
int main(void) {
	float grossprice, taxrate, netprice, taxvalue;
	do{
		cout << "Enter a gross price: ";
		cin >> grossprice;
	}while(grossprice <= 0);
	do{
		cout << "Enter a tax rate: ";
		cin >> taxrate;
	}while(taxrate <= 0 || taxrate > 100);

	taxvalue = grossprice*taxrate/(100+taxrate);
	netprice = grossprice - taxvalue;

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	system("pause");
	return 0;
}