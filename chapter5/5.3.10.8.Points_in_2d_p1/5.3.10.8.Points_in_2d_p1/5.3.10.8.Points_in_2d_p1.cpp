// 5.3.10.8.Points_in_2d_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
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
	
	double distanceTo(Point2D that){
		return sqrt(pow(this->x-that.x,2)+pow(this->y - that.y ,2));
	}
private:
	double x;
	double y;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Point2D a(-3,-6.7);
	Point2D b(-8.5,9);
	cout<<setprecision(10)<<a.distanceTo(b);
	
	return 0;
}

