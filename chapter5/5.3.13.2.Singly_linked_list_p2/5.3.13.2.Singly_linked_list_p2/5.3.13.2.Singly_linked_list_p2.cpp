// 5.3.13.2.Singly_linked_list_p2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
class Node
{
public:
	Node():value(0){}
	Node(int val): value(val), next(nullptr){cout << "+Node" << endl;}
	~Node(){cout << "-Node" << endl;};
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
private:
	Node* head;
};

int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	int value = 0;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	while (list.pop_front(value))
		cout << value << endl;
	return 0;
}

