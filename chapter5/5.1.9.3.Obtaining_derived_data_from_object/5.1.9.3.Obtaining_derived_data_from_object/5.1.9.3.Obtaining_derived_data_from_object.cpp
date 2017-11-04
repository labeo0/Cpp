// 5.1.9.3.Obtaining_derived_data_from_object.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side)
	{
		set_side(side);
	}
	void set_side(double side);
	double get_area();
private:
	double side;
};
void AdHocSquare::set_side(double side)
{
	if(side>=0)
		this->side = side;
	else if(this->side == NULL)
		this->side = 0;
}
double AdHocSquare::get_area()
{
	return this->side*this->side;
}

class LazySquare
{
public:
	LazySquare(double side)
	{
		set_side(side);
		this->area = this->side*this->side;
	}
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};
void LazySquare::set_side(double side)
{
	if(side>=0){
		this->side = side;
		this->side_changed = 1;
	}
	else if(this->side == NULL)
		this->side = 0;
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

int _tmain(int argc, _TCHAR* argv[])
{
	LazySquare ls(2);
	cout<<ls.get_area()<<endl;
	ls.set_side(3);
	cout<<ls.get_area()<<endl;

	AdHocSquare ad(4);
	cout<<ad.get_area()<<endl;
	ad.set_side(5);
	cout<<ad.get_area()<<endl;

	return 0;
}

