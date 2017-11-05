// 5.3.10.3.Gym_membership_managment.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Member
{
public:
	Member(){id = 0; name = ""; month = 0;}
	Member(int id, string name, int month)
	{
		if(id >= 0)
			this->id = id;
		else
			this->id = 0;

		this->name = name;

		if(month >= 0)
			this->month = month;
		else
			this->month = 0;
	}
	int getId(){return id;}
	void printMember()
	{
		std::cout<<"Member "<<id<<" : "<<name<<", subscription valid for "<<month<<" months\n";
	}
	bool extendShip(int n)
	{
		if(n>=0)
		{
			month+=n; return 1;
		}
		else
			return 0;	
	}
	void cancleShip(){month = 0;}
private:
	int id;
	string name;
	int month;
};
void printList(Member *list)
{
	bool noMembers = true;
	for(int i = 0; i < 10; i++)
	{
		if(list[i].getId()!=0)
		{
			list[i].printMember();
			noMembers = false;
		}
	}
	if(noMembers)
		std::cout<<"No members yet\n";
}
int findById(Member *list, int id)//return -1 if no such id
{
	for(int i = 0; i < 10; i++)
		if(list[i].getId() == id)
			return i;
	return -1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Member list[10];
	list[0] = Member(1,"Vasya",1);
	list[1] = Member(2,"Kolya",2);

	string command, comWord, id, num, name;
	while (command != "quit")
	{
		printList(list);
		std::cout << "What would you like to do?: ";
		std::getline(std::cin,command);
		comWord = command.substr(0,command.find(' '));
		command = command.substr(command.find(' ')+1, std::string::npos);
		id = command.substr(0,command.find(' '));
		num = command.substr(command.find(' ')+1, std::string::npos);
		name = num;
		if(comWord == "create")
		{
			int i = findById(list,0);//find first free index
			int check = findById(list,std::stoi(id));//returns index if id already used
			if(std::stoi(id)==0)
				std::cout<<"You cant create user id = 0 !\n";
			else if(i>=0 && check<0 )
			{
				list[i] = Member(std::stoi(id),name,0);
				std::cout<<"Member created successfully\n";
			}
			else if(i<0)
				std::cout<<"Cant create more than 10 members!\n";
			else if( check >=0 )
				std::cout<<"Member with such id already exists!\n";
		}
		else if(comWord == "delete")
		{
			int check = -1;
			if(std::stoi(id) != 0)
				check = findById(list,std::stoi(id));
			if(check >= 0)
			{
				list[check] = Member();
				std::cout<<"Member was successfully deleted\n";
			}
			else
				std::cout<<"There is no member with such id\n";
		}
		else if(comWord == "extend")
		{
			int check = -1;
			if(std::stoi(id) != 0)
				check = findById(list,std::stoi(id));
			if(check >= 0)
			{
				if(list[check].extendShip(std::stoi(num)))
					std::cout<<"MemberShip was successfully extended\n";
				else
					std::cout<<"Cant extend by negative numbers\n";
			}
			else
				std::cout<<"There is no member with such id\n";
		}
		else if(comWord == "cancel")
		{
			int check = -1;
			if(std::stoi(id) != 0)
				check = findById(list,std::stoi(id));
			if(check >= 0)
			{
				list[check].cancleShip();
				std::cout<<"MemberShip was successfully cancled\n";
			}
			else
				std::cout<<"There is no member with such id\n";
		}

	}

	return 0;
}

