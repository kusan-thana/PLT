#include "gui.hpp"	
#include "moveCommand.hpp"
#include "modeCommand.hpp"
#include "loadCommand.hpp"

#include <iostream>

using namespace gui;

GUI::GUI(state::LevelState& levelState, engine::Engine& engine) : levelState(levelState), cursorList(*this), engine(engine){
	cursorList.setGuiElement(0, new Cursor(levelState));
	this->init();
}
GUI::~GUI(){
}
void GUI::init() {
	std::cout << std::endl << "Utiliser la souris ou le clavier pour jouer (espace ou clic gauche pour selectionner)" << std::endl;
	engine::LoadCommand* load = new engine::LoadCommand("../res/level2.txt");
	//~ engine.addCommand(load); //initialiser ici le 1er niveau

}

GUIElementList& GUI::getCursor()
{
	return cursorList;
}

void GUI::setCursor(const GUIElementList& cursor)
{
	//~ this->cursor = cursor;
}

void gui::GUI::setEngineMode(engine::EngineMode engineMode)
{
	this->engineMode = engineMode;
}

void GUI::commander(engine::Engine& engine) {

	Cursor* cursor = (Cursor*)cursorList.getGuiElement(0);

	if (cursor->getActive()) {
		cursor->setcharacter(levelState.getElementList().getElement(cursor->getX(), cursor->getY()));
	}
	if (!cursor->getActive() && cursor->getcharacter()) {
		engine::MoveCommand* move = new engine::MoveCommand(cursor->getX(), cursor->getY(), cursor->getcharacter());
		cursor->setcharacter(levelState.getElementList().getElement(cursor->getX(), cursor->getY()));
		engine.addCommand(move);
	}
	if (engineMode) {
		engine::ModeCommand* engineModeCommand = new engine::ModeCommand(engineMode);
		engine.addCommand(engineModeCommand);
		engineMode = engine::PLAY;
	}

}


