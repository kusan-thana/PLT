#include "gui.hpp"	
#include "moveCommand.hpp"
#include "modeCommand.hpp"
#include "loadCommand.hpp"
#include "cursor.hpp"
#include "guiTile.hpp"
#include "mobileElement.hpp"
#include "guiTile.hpp"
#include <iostream>

using namespace gui;

GUI::GUI(state::LevelState& levelState, engine::Engine& engine) : levelState(levelState), cursorList(*this), moveRange(*this), engine(engine), healthBarList(*this){
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
GUIElementList& GUI::getCursorList()
{
	return cursorList;
}
GUIMoveRange& GUI::getMoveRange(){
	
	return this->moveRange;
}
GUIElementList& GUI::getHealthBarList(){
	
	return this->healthBarList;
}
state::LevelState& GUI::getLevelState(){

	return this->levelState;
}
void GUI::setCursorList(const GUIElementList& cursor)
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
		cursor->setCharacter(levelState.getElementList().getElement(cursor->getX(), cursor->getY()));
		moveRange.setElement(cursor->getCharacter());
		moveRange.computeRange();
		moveRange.notifyObservers(-1);
	}
	else {
		moveRange.clear();
		moveRange.notifyObservers(-1);
		healthBarList.clear();
		updateHealthBarList();
	}
	
	if (!cursor->getActive() && cursor->getCharacter()) {
		engine::MoveCommand* move = new engine::MoveCommand(cursor->getX(), cursor->getY(), cursor->getCharacter());
		cursor->setCharacter(levelState.getElementList().getElement(cursor->getX(), cursor->getY()));
		engine.addCommand(move);
	}
	if (engineMode) {
		engine::ModeCommand* engineModeCommand = new engine::ModeCommand(engineMode);
		engine.addCommand(engineModeCommand);
		engineMode = engine::PLAY;
	}
}
void GUI::updateHealthBarList(){
	
	state::ElementList characters = levelState.getElementList();
	int size = characters.size();
			//~ std::cout << "size : " << size << std::endl; 
	for(int i=0; i<size; i++){

		state::MobileElement* element = (state::MobileElement*)characters.getElement(i);

			int x = element->getX();
			int y = element->getY();
			healthBarList.setGuiElement(i, new GUITile(x,y,GUITypeId::HEALTH_BAR));

	}
}

