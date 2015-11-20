#include "gui.hpp"	
#include "moveCommand.hpp"
#include "modeCommand.hpp"
#include "loadCommand.hpp"

#include <iostream>

using namespace gui;

GUI::GUI(state::LevelState& levelState, engine::Engine& engine) : levelState(levelState), cursor(*this, levelState), engine(engine){
	this->init();
}
GUI::~GUI(){
}
void GUI::init() {
	std::cout << std::endl << "Utiliser la souris ou le clavier pour jouer (espace ou clic gauche pour selectionner)" << std::endl;
	engine::LoadCommand* load = new engine::LoadCommand("../res/level2.txt");
	engine.addCommand(load); //initialiser ici le 1er niveau

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
		cursor.setcharacter(levelState.getElementList().getElement(cursor.getX(), cursor.getY()));
		engine.addCommand(move);
	}
	if (engineMode) {
		engine::ModeCommand* engineModeCommand = new engine::ModeCommand(engineMode);
		engine.addCommand(engineModeCommand);
		engineMode = engine::PLAY;
	}

}


