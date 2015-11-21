#include "cursor.hpp"
#include "gui.hpp"
#include "guiEvent.hpp"

using namespace gui;

Cursor::Cursor(state::LevelState& levelState) : levelState(levelState)
{
}
Cursor::~Cursor()
{					
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
void Cursor::setActive(bool active) {

		if (active == true && levelState.getElementList().getElement(x,y)){
			if (levelState.getElementList().getElement(x, y)->getTypeID() == state::HERO){
				this->active = active;
			}
		}
		else
			this->active = false;
}
void Cursor::setcharacter(state::Element* character) {
	
	this->character = character;
}
state::Element* Cursor::getcharacter() {

	return character;
}
GUITypeId Cursor::getGuiTypeId() const{

	return GUITypeId::CURSOR;
}
