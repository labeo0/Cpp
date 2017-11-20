// 5.2.13.8.Double_linked_list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Node
{
public:
	Node():value(0){}
	Node(int val): value(val), next(nullptr), prev(nullptr){}
	~Node(){};
	int value;
	Node* next;
	Node* prev;
};

class List
{
public:
	List(): head(nullptr), tail(nullptr){}
	List(List &that)
	{
		int size = that.size();
		this->head = new Node(that.head->value);
		Node* headCopy = this->head;
		Node* thatHeadCopy = that.head;

		for(int i = 0; i < size -1;i++)
		{
			this->head->next = new Node(that.head->next->value);
			this->head->next->prev = head;
			that.head = that.head->next;
			this->head = this->head->next;
		}
		this->tail = this->head;
		that.head = thatHeadCopy;
		this->head = headCopy;
	}
	void push_front(int value)
	{
		Node* new_Node = new Node(value);
		
		if(head == nullptr)
		{
			head = new_Node;
			head->next = nullptr;
			head->prev = nullptr;
			tail = head;
		}
		else
		{
			new_Node = head;
			head = new Node(value);
			head->next = new_Node;
			head->prev = nullptr;
			new_Node->prev = head;
		}
		
		
	}
	bool pop_front(int& value)
	{
		Node* temp = head;
		if(head == nullptr)
			return false;
		if(head->next == nullptr)
		{
			value = head->value;
			temp = head;
			head = nullptr;
		}
		else
		{
			head->next->prev = nullptr;
			head = head->next;
			value = temp->value;
		}
		delete temp;
		return true;
	}
	void push_back(int value)
	{
		Node* new_tail = new Node(value);
		if (head == nullptr)
		{
			head = new_tail;
			tail = new_tail;
			head->prev = nullptr;
		}
		else
		{
			new_tail->prev = tail;
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
			element = tail;
			value = tail->value;
			tail->prev->next = nullptr;
			tail=tail->prev;
			delete element;
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
		for(int i = 0; i < index - 1; i++)
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
void printList(List &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == "<< list.at(i) << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	int value;

	list.push_front(3);
	list.push_front(2);
	list.push_front(1);

	printList(list);

	cout << endl;

	list.insert_at(2, 0);

	printList(list);

	List list2(list);

	cout << endl;
	
	while (list2.pop_back(value))
		cout << value << endl;

	cout << endl;
	printList(list);

	cout << endl;
	printList(list2);

	return 0;
	
	return 0;
}

