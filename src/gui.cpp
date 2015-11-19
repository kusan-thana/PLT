#include "gui.hpp"	
#include "moveCommand.hpp"
#include "modeCommand.hpp"

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

void gui::GUI::setEngineMode(engine::EngineMode engineMode)
{
	this->engineMode = engineMode;
}

void GUI::commander(engine::Engine& engine) {

	if (cursor.getActive()) {
		cursor.setcharacter(levelState.getElementList().getElement(cursor.getX(), cursor.getY()));
	}
	if (!cursor.getActive() && cursor.getcharacter()) {
		engine::MoveCommand* move = new engine::MoveCommand(cursor.getX(), cursor.getY(), cursor.getcharacter());
		//std::cout << move->getTypeId() << std::endl;
		cursor.setcharacter(levelState.getElementList().getElement(cursor.getX(), cursor.getY()));
		engine.addCommand(move);
		//std::cout << move->getTypeId();
	}
	if (engineMode) {
		engine::ModeCommand* engineModeCommand = new engine::ModeCommand(engineMode);
		engine.addCommand(engineModeCommand);
		engineMode = engine::PLAY;
	}

}


