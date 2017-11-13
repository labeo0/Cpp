// 5.3.10.8.Points_in_2d_p2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
class Point2D{
public:
	Point2D(double x, double y){
		this->x = x;
		this->y = y;
	}
	void printPoiint(){
		cout<<"x = "<<x<<"; y = "<<y<<endl;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	double distanceTo(Point2D that){
		return sqrt(pow(this->x-that.x,2)+pow(this->y - that.y ,2));
	}
private:
	double x;
	double y;
};
class Line2D{
public:
	Line2D(double slope, double y_intercept)
	{
		this->slope = slope;
		this->y_intercept = y_intercept;
	}
	Line2D(Point2D a, Point2D b){
		this->slope = (b.getY() - a.getY())/(b.getX() - a.getX());
		this->y_intercept =(b.getX()*a.getY() - a.getX()*b.getY())/(b.getX() - a.getX());
	}
	string ToString(){
		stringstream s;
		if(y_intercept >= 0)
			s<<"y = "<<slope<<"x + "<<y_intercept;
		else
			s<<"y = "<<slope<<"x "<<y_intercept;
		return s.str();
	}
private:
	double slope;
	double y_intercept;
};


int _tmain(int argc, _TCHAR* argv[])
{
	Point2D a(2,2);
	Point2D b(-2,0);
	Line2D l(a,b);
	cout<< l.ToString()<<endl;
	return 0;
}

