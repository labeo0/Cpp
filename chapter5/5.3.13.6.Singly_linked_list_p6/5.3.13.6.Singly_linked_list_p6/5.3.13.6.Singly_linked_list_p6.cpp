// 5.3.13.6.Singly_linked_list_p6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


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
	bool pop_back(int& value)
	{
		Node* element = head;
		if(element == nullptr)
			return false;
		if(element == tail)
		{
			value = tail->value;
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			while(element->next != tail)
			{
				element= element->next;
			}
			value = element->next->value;//get last element
			delete element->next;
			element->next = nullptr;//last element = nullptr
			tail = element;//tail = pre last element
		}
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
	int at(int index)
	{
		int res;
		Node *element = head;
		for(int i = 0; i <index; i++)
		{
			element = element->next;
		}
		res = element->value;
		return res;
	}
	void insert_at(int index, int value)
	{
		
		Node *Element = head;
		Node *newNode = new Node(value);
		if(index == 0)
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		for(int i = 0; i - 1 < index; i++)
		{
			Element = Element->next;
		}
		newNode->next = Element->next;
		Element->next = newNode;
		
	}
	void remove_at(int index)
	{
		Node *Element = head;
		Node *Temp = nullptr;
		for(int i = 0; i < index - 1;i++)
		{
			Element = Element->next;
		}
		if(Element->next->next!=nullptr)//check if there are elements after deleted one
			Temp= Element->next->next;
		delete Element->next;
		Element->next = Temp;
	}
private:
	Node* head;
	Node* tail;
};
void printList(List list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == "<< list.at(i) << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	//
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	printList(list);
	cout << endl;

	list.remove_at(2);
	printList(list);
	cout << endl;
	
	list.insert_at(0, 6);
	printList(list);
	return 0;
}

