// 6.3.6.1.Polymorphism_p2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class Piece
{
public:
	Piece():num(0),letter(97){}
	virtual bool move(char letter, int num){return 1;}
protected:
	int num;
	char letter;
};
class Man: public Piece
{
public:
	Man():Piece(){}
	Man(char letter, int num)
	{
		this->letter = letter;
		this->num = num;
	}
	bool move(char letter, int num)
	{
		if(!CoordAreOnBoard(letter,num))// cant move outside of board
			return false;

		if( this->letter+1==letter && this->num+1==num)//diagonal move to the right forward
			return true;
		if(this->letter-1 == letter && this->num+1==num)//diagonal move to the left forward
			return true;

		return false;
	}
private:
	bool CoordAreOnBoard(char letter,int num)
	{//check if coordinates are on chessboard
		if(letter < 97 || letter > 104)//a=97,h=104
			return 0;
		if(num < 1 || num > 8)
			return 0;

		return 1;
	}
};
class King: public Piece
{
public:
	King():Piece(){}
	King(char letter, int num)
	{
		this->letter = letter;
		this->num = num;
	}
	bool move(char letter, int num)
	{
		if(!CoordAreOnBoard(letter,num))
			return false;
		/*
			Chess board = decart/cartesiam coordinates;
			Coordinates of King and coord of destination is a line
			y=k*x+b;
			if k=1 or k=-1 (angle beetween line and x-axis = 45 or = 135)
			(King and Dest are on same diagonal)
			then King can move
		*/
		
		if(abs(double(num - this->num)/(letter - this->letter))==1 )
			return true;
		return false;

	}
private:
	bool CoordAreOnBoard(char letter,int num)
	{//check if coordinates are on chessboard
		if(letter < 97 || letter > 104)//a=97,h=104
			return 0;
		if(num < 1 || num > 8)
			return 0;

		return 1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Piece *man = new Man('b',1);
	Piece *king = new King('b',1);
	std::cout<<man->move('c',2)<<std::endl;
	std::cout<<king->move('d',3)<<std::endl;
	std::cout<<man->move('d',3)<<std::endl;
	std::cout<<man->move('a',2)<<std::endl;
	return 0;
}

