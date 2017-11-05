// 5.3.10.3.Flight_booking_system_p3.cpp: определяет точку входа для консольного приложения.
//just realized i could make sbclass flightbooking[] and put there methods like print all flights or find if id is used
//eh, one more thing i will do later

#include "stdafx.h"
#include <iostream>
#include <string>
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking(void){ id = 0; capacity = 0; reserved = 0;}
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
	int getId() { return id;}
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
	FlightBooking booking [10];
	int num;//used int create//contain index of not used booking

	booking[0] = FlightBooking(1, 400, 0);

	std::string command = "", comWord, id, n;

	while (command != "quit")
	{
		for(int i = 0; i < 10; i++)
		{
			if(booking[i].getId()!=0)
				booking[i].printStatus();
		}
		std::cout << "What would you like to do?: ";
		std::getline(std::cin,command);
		comWord = command.substr(0,command.find(' '));
		command = command.substr(command.find(' ')+1, std::string::npos);
		id = command.substr(0,command.find(' '));
		n = command.substr(command.find(' ')+1, std::string::npos);

#pragma region if(comWord == add)
		if(comWord == "add")
		{
			int i = 0;
			while(!(booking[i].getId()==std::stoi(id)) && i < 11)
				i++;
			if(i!=10)
			{
				if(booking[i].reserveSeats(std::stoi(n)))
					std::cout<<n<<" seats reserved successfully!\n";
				else
					std::cout<<"You cant reserve seats more than 105% of capacity!\n";
			}
			else
				std::cout<<"Flight with such id not found\n";
		}
#pragma endregion if(comWord == add)
#pragma region if(comWord == cancel)
		else if(comWord == "cancel")
		{
			int i = 0;
			while(!(booking[i].getId()==std::stoi(id)) && i < 11)
				i++;
			if(i!=10)
			{
				if(booking[i].cancelReservations(std::stoi(n)))
					std::cout<<n<<" seats canceled successfully!\n";
				else
					std::cout<<"Reservation cant be less than 0!\n";
			}
			else
				std::cout<<"Flight with such id not found\n";
		}
#pragma endregion if(comWord == cancel)
#pragma region (comWord == "create")
		else if(comWord == "create")
		{
			num = -1;
			bool idIsUsed = false;
			for(int i = 0; i < 10 && num == -1; i++)//get id of first booking with id=0(empty booking)
				if(booking[i].getId()==0)
					num = i;

			for(int i  = 0; i < 10 && !idIsUsed; i++)
				if(booking[i].getId()==std::stoi(id))
					idIsUsed = true;

			if(std::stoi(id)==0)
				std::cout<<"Sorry, you cant use id = 0";
			else if(!idIsUsed)
			{
				booking[num] = FlightBooking(std::stoi(id),std::stoi(n),0);
				std::cout<<"The Flight was successfully created\n";
			}
			else if(idIsUsed)
				std::cout<<"Flight with such id already exists!\n";
			else if(num == -1)
			{
				std::cout<<"Only 10 flights can exist at once!\n";
			}
			else
				std::cout<<"An error occured. We are doing our best to fix it\n";		
		}
#pragma endregion (comWord == "create")
		else if(comWord == "delete")
		{
			int i = 0;
			while(!(booking[i].getId()==std::stoi(id)) && i < 11)
				i++;
			if(i!=10)
				booking[i] = FlightBooking();
			else
				std::cout<<"Flight with such id not found\n";
		}
	}
	return 0;
}


