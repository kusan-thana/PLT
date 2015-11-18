#include "cursor.hpp"
#include "gui.hpp"
#include "guiEvent.hpp"

using namespace gui;

Cursor::Cursor(GUI& gui,state::LevelState& levelState) : gui(gui), x(0), y(0), levelState(levelState), character(0)
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
	if (x < levelState.getElementGrid().getHeight() && x >= 0)
		this->x = x;
}

void Cursor::setY(int y)
{
	if (y < levelState.getElementGrid().getWidth() && y >= 0)
		this->y = y;
}
GUI& Cursor::getGUI() {

	return gui;
}
void Cursor::notifyObservers(int i) {
	
	GUIEvent GUIEvent(*this,i);
	GUIObservable::notifyObservers(GUIEvent);
}

bool Cursor::getActive() {
	return active;
}

void Cursor::setActive(bool active) {
		if (active == true && levelState.getElementList().getElement(0)->getX() == x && levelState.getElementList().getElement(0)->getY() == y)
			this->active = active;
		else
			this->active = false;
}

void Cursor::setcharacter(int character) {
	this->character = character;

}

int Cursor::getcharacter() {
	return character;
}