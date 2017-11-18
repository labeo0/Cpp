// 5.3.13.4.Singly_linked_list_p4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Node
{
public:
	Node():value(0){}
	Node(int val): value(val), next(nullptr){}
	~Node(){};
	int value;
	Node* next;
};

class List
{
public:
	List(): head(nullptr), tail(nullptr){}
	void push_front(int value)
	{
		Node* new_head = new Node(value);
		new_head->next = head;
		if(head == nullptr)
			tail = new_head;
		head=new_head;
	}
	bool pop_front(int& value)
	{
		if(head == nullptr)
			return false;
		Node* new_head = head->next;
		value = head->value;
		delete head;
		head = new_head;

		return true;
	}
	void push_back(int value)
	{
		Node* new_tail = new Node(value);
		if (head == nullptr)
		{
			head = new_tail;
			tail = new_tail;
		}
		else
		{
			tail->next = new_tail;
			tail = new_tail;
		}
	}
	int size()
	{
		int count = 0;
		Node* newHead = head;
		while(newHead != nullptr)
		{
			count++;
			newHead = newHead->next;
		}
		delete newHead;
		return count;
	}
private:
	Node* head;
	Node* tail;
};

int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	//
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	int value = 0;
	while (list.pop_front(value))
	{
		cout << value << endl;
	}
	return 0;
}

