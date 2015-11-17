#include "gui.hpp"
#include "positionCommand.hpp"

using namespace gui;

GUI::GUI(state::LevelState& levelState, engine::Engine&) : levelState(levelState), cursor(*this, levelState), engine(engine){
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

void GUI::commander() {
	engine::PositionCommand move(cursor.getX(), cursor.getY());

}


