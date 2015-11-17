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
		engine::PositionCommand* move = new engine::PositionCommand(cursor.getX(), cursor.getY());
		//std::cout << move->getTypeId() << std::endl;

		engine.addCommand(move);
		//std::cout << move->getTypeId();
	}

}


