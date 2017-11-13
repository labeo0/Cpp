// 5.3.10.11.Inheritance_basics_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class FarmAnimal{
public:
	FarmAnimal(double water_consumption)
	{
		this->water_consumption = water_consumption;
	}
	double getWaterConsumption()
	{
		return water_consumption;
	}

private:
	double water_consumption;
};

class DummyAnimal : public FarmAnimal{
public:
	DummyAnimal(): FarmAnimal(10.0)
	{

	}
};

class DoublingAnimal : public FarmAnimal
{
public:
	DoublingAnimal(double given_water_consumption): FarmAnimal(2 * given_water_consumption) 
	{
	}
};


void printConsumption(FarmAnimal animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption()
		<< " liters of water" << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	FarmAnimal animalA(5);
	DummyAnimal animalB;
	DoublingAnimal animalC(21);
	cout << "animal consumes " << animalA.getWaterConsumption()
		<< " liters of water." << endl;
	cout << "What about the others?" << endl;
	printConsumption(animalB);
	printConsumption(animalC);

	FarmAnimal doub =  DoublingAnimal(1);
	DummyAnimal aaa();
	
	printConsumption(doub);

	return 0;
}

