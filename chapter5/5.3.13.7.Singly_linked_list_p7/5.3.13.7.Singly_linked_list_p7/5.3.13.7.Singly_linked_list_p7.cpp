// 5.3.13.7.Singly_linked_list_p7.cpp: определяет точку входа для консольного приложения.
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
	List(List &that)
	{
		int size = that.size();
		this->head = new Node(that.head->value);
		Node* headCopy = this->head;
		Node* thatHeadCopy = that.head;

		for(int i = 0; i < size -1;i++)
		{
			this->head->next = new Node(that.head->next->value);
			that.head = that.head->next;
			this->head = this->head->next;
		}
		this->tail = this->head;
		that.head = thatHeadCopy;
		this->head = headCopy;
	}
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
void printList(List &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == "<< list.at(i) << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	List list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	cout << "list1" << endl;
	printList(list1);
	cout << endl;

	List list2(list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	list1.insert_at(1, 6);
	list2.remove_at(2);
	cout << "list1" << endl;
	printList(list1);

	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	return 0;
}

