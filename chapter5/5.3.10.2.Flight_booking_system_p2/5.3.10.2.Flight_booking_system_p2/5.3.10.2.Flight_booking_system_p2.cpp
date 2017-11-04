// 5.3.10.2.Flight_booking_system_p2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
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
	//reserve can be 105% of capacity
	this->id = id;
	this->capacity = capacity;
	if(reserved*100/capacity > 105)
		this->reserved = 105*capacity/100;
	else if(reserved < 0)
		this->reserved = 0;
	else
		this->reserved = reserved;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	// try to add reservations and return 'true' on success
	// keep the limits in mind
	if((reserved+number_ob_seats)*100/capacity <= 105)
	{
		reserved+=number_ob_seats;
		return true;
	}
	return false;
}
bool FlightBooking::cancelReservations(int number_ob_seats)
{
	// try to cancel reservations and return 'true' on success
	// keep the limits in mind
	if(reserved >= number_ob_seats)
	{
		reserved-=number_ob_seats;
		return true;
	}
	return false;
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
	std::string command = "", comWord, n;
	while (command != "quit")
	{
		booking.printStatus();
		std::cout << "What would you like to do?: ";
		std::getline(std::cin,command);
		comWord = command.substr(0,command.find(' '));
		n = command.substr(command.find(' ')+1, std::string::npos);
		if(comWord == "add")
		{
			if(booking.reserveSeats(std::stoi(n)))
				std::cout<<n<<" seats reserved successfully!\n";
			else
				std::cout<<"You cant reserve seats more than 105% of capacity!\n";
		}
		else if(comWord == "cancel")
		{
			if(booking.cancelReservations(std::stoi(n)))
				std::cout<<n<<" seats canceled successfully!\n";
			else
				std::cout<<"You cant cancel reservations more than capacity!\n";
		}
	}
	return 0;
}

