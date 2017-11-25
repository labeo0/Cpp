// 6.3.5.1.Polymorphism_p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class Tree
{
public:
	Tree(){}
	virtual void draw()
	{
		std::cout<<"SuperClass drawing:\nInsvisible Tree!\n";
	}
};
class Tree1 : public Tree
{
public:
	Tree1():Tree(){}
	void draw()
	{
		std::cout<<"Tree1 drawing:\n /\\\n//\\\\\n";
	}
};
class Tree2 : public Tree
{
public:
	Tree2():Tree(){}
	void draw()
	{
		std::cout<<"Tree2 drawing:\n /\\\n/**\\\n";
	}
};
class Tree3 : public Tree
{
public:
	Tree3():Tree(){}
	void draw()
	{
		std::cout<<"Tree3 drawing:\n /\\\n/##\\\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Tree *trees[3];
	trees[0] = new Tree1();
	trees[1] = new Tree2();
	trees[2] = new Tree3();

	for(int i = 0; i < 3; i++)
		trees[i]->draw();
	return 0;
}

