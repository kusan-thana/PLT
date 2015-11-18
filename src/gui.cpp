#include "gui.hpp"
#include "positionCommand.hpp"

#include <iostream>

using namespace gui;

GUI::GUI(state::LevelState& levelState) : levelState(levelState), cursor(*this, levelState){
}
GUI::~GUI(){
}

Cursor& GUI::getCursor()
{
	return cursor;
}

void GUI::setCursor(const Cursor& cursor)
{
	//~ this->cursor = cursor;
}

void GUI::commander(engine::Engine& engine) {

	if (cursor.getActive()){
		if (levelState.getElementList().getElement(0)->getX() == cursor.getX() && levelState.getElementList().getElement(0)->getY() == cursor.getY())
			cursor.setcharacter(1);
		else
			cursor.setcharacter(0);
	}
	if (!cursor.getActive() && cursor.getcharacter()){
		engine::PositionCommand* move = new engine::PositionCommand(cursor.getX(), cursor.getY());
		//std::cout << move->getTypeId() << std::endl;
		cursor.setcharacter(0);
		engine.addCommand(move);
		//std::cout << move->getTypeId();
	}

}


