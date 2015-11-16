#pragma once
class Cursor
{
protected: 
	int x;
	int y;
public:
	Cursor(int x, int y);
	~Cursor();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

