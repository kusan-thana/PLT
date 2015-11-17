#include "gui.hpp"

using namespace gui;

GUI::GUI(state::LevelState& levelState) : levelState(levelState), cursor(*this) {
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

