#include "cursor.hpp"
#include "gui.hpp"
#include "guiEvent.hpp"
#include "mobileElement.hpp"

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
			if (((state::MobileElement*)(levelState.getElementList().getElement(x, y)))->isPlayerCharacter() == true){
				if (((state::MobileElement*)(levelState.getElementList().getElement(x, y)))->getTurnPlayed() == false)
					this->active = active;
			}
		}
		else
			this->active = false;
}
void Cursor::setCharacter(state::Element* character) {
	
	this->character = character;
}
state::Element* Cursor::getCharacter() {

	return character;
}
GUITypeId Cursor::getGuiTypeId() const{

	return GUITypeId::CURSOR;
}
