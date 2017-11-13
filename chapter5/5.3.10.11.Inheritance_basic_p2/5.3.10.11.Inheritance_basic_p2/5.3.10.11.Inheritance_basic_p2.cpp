// 5.3.10.11.Inheritance_basic_p2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class FarmAnimal{
public:
	FarmAnimal()
	{
		water_consumption = 0;
	}
	FarmAnimal(double water_consumption)
	{
		this->water_consumption = water_consumption;
	}
	double getWaterConsumption()
	{
		return water_consumption;
	}
protected:
	double water_consumption;
};

class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator()
	{
		total_consumption = 0;
	}
	double getTotalConsumption()
	{
		return total_consumption;
	}
	void addConsumption(FarmAnimal animal)
	{
		total_consumption += animal.getWaterConsumption();
	}
private:
	double total_consumption;
};

class Sheep:public FarmAnimal
{
public:
	Sheep(double weight): FarmAnimal()
	{
		this->water_consumption = weight*1.1/10;
	}
};
class Horse:public FarmAnimal
{
public:
	Horse(double weight):FarmAnimal()
	{
		this->water_consumption = weight*6.8/100;
	}
};
class Cow:public FarmAnimal
{
public:
	Cow(double weight):FarmAnimal()
	{
		this->water_consumption = weight*5.6/100;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string str = " ";
	string animal,weight;
	ConsumptionAccumulator acc;
	while(str!="")
	{
		getline(cin,str);
		animal = str.substr(0,str.find(" "));
		weight = str.substr(str.find(" ")+1,string::npos);
		if(animal == "sheep")
		{
			FarmAnimal sheep = Sheep(stoi(weight));
			acc.addConsumption(sheep);
		}
		else if(animal =="horse")
		{
			FarmAnimal horse = Horse(stoi(weight));
			acc.addConsumption(horse);
		}
		else if(animal =="cow")
		{
			FarmAnimal cow = Cow(stoi(weight));
			acc.addConsumption(cow);
		}
	}
	cout<<"Total water consumption: "<<acc.getTotalConsumption()<<" liters\n";
	return 0;
}

