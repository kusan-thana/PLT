#include "cursor.hpp"



Cursor::Cursor(int x, int y) : x(x), y(y)
{
}


Cursor::~Cursor()
{					
}

int Cursor::getX()
{
	return x;
}

int Cursor::getY()
{
	return y;
}

void Cursor::setX(int x)
{
	this->x = x;
}

void Cursor::setY(int y)
{
	this->y = y;
}


