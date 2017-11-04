// 5.3.10.1Flight_booking_system_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	std::cout<< "Flight "<<id<<" : "<<reserved<<"/"<<capacity<<" ("<<reserved*100/capacity<<"%) seats taken\n";
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int reserved = 0,
		capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;
	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();

	return 0;
}

