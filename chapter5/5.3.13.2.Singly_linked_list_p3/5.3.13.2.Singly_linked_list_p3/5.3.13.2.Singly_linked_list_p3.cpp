// 5.3.13.2.Singly_linked_list_p3.cpp: определяет точку входа для консольного приложения.
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
	List(): head(nullptr){}
	void push_front(int value)
	{
		Node* new_head = new Node(value);
		new_head->next = head;
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
};

int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	int val = 0;
	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}
	cout << endl;
	for (int i = 1; i <= 3; i++)
	{
		int value;
		list.pop_front(val);
		cout << "popped " << val << ", size: " << list.size() << endl;
	}
	return 0;
}

