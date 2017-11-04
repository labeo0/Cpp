#include <iostream>
#include <string>
using namespace std;
class Square
{
public:
	void set_side(double side);
	void print();
private:
	double side;
	double area;
	
};
void Square::set_side(double side)
{ 
	if(side > 0){
	this->side = side;
	this->area = side * side;
	}
}
void Square::print()
{
	cout << "Square: side=" << this->side << " area="<< this->area << endl;
}
int main()
{
	Square sq;
	sq.set_side(2);
	sq.print();

	sq.set_side(0);
	sq.print();

	system("pause");
		return 0;
}
