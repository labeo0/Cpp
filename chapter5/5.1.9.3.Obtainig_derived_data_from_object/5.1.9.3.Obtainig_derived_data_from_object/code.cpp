#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
};
void AdHocSquare::set_side(double side)
{
	if(side>0)
		this->side = side;
}
double AdHocSquare::get_area()
{
	return this->side*this->side;
}

class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};
void LazySquare::set_side(double side)
{
	if(side>0){
		this->side = side;
		this->side_changed = 1;
	}
}
double LazySquare::get_area()
{
	if(this->side_changed)
	{
		this->area = this->side*this->side;
		this->side_changed = 0;
		return this->area;
	}
	else
		return this->area;
}
int main()
{
	LazySquare ad(2);
	//ad.get_area();


	system("pause");
	return 0;
}