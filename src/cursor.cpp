#include "cursor.hpp"
#include "GUI.hpp"
#include "GUIEvent.hpp"

using namespace gui;

Cursor::Cursor(GUI& gui) : gui(gui), x(0), y(0)
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
GUI& Cursor::getGUI() {

	return gui;
}
void Cursor::notifyObservers(int i) {
	
	GUIEvent GUIEvent(*this,i);
	GUIObservable::notifyObservers(GUIEvent);
}

