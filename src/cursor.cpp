#include "cursor.hpp"
#include "ihm.hpp"
#include "ihmEvent.hpp"

using namespace ihm;

Cursor::Cursor(IHM& ihm) : ihm(ihm), x(0), y(0)
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
IHM& Cursor::getIhm() {

	return ihm;
}
void Cursor::notifyObservers(int i) {
	
	IHMEvent ihmEvent(*this,i);
	IHMObservable::notifyObservers(ihmEvent);
}

