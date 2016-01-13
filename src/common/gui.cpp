#include "gui.hpp"	
#include "engine.hpp"
#include "gui.hpp"
#include <iostream>
#include "server.hpp"
using namespace gui;

GUI::GUI(state::LevelState& levelState, engine::Engine& engine, server::Server& server) : levelState(levelState), cursorList(*this), moveRange(*this), engine(engine),startPlayerAI(false), engineMode(engine::PLAY), server(server){
	cursorList.setGuiElement(0, new Cursor(levelState));
	this->init();
}
GUI::~GUI(){
}
void GUI::init() {

	std::cout << std::endl << "Manuel de jeu : \n"
		<< "Selection : espace ou clic gauche\nDeselectionner: Echap ou clic droit\nDouble selectionner un personnage pour terminer son tour\n"
		<< "Save state : S\nLoad saved state : L\n "
		<< "\nMODE AUTO (Commandes Player : HeuristicAI) : ENTREE" << std::endl;	engine::LoadCommand* load = new engine::LoadCommand("../res/level2.txt");
	//~ engine.addCommand(load); //initialiser ici le 1er niveau
}
void GUI::setStartPlayerAI(bool startPlayerAI)
{
	this->startPlayerAI = startPlayerAI;
}
bool GUI::getStartPlayerAI()
{
	return startPlayerAI;
}
GUIElementList& GUI::getCursorList()
{
	return cursorList;
}
GUIMoveRange& GUI::getMoveRange(){
	
	return this->moveRange;
}
state::LevelState& GUI::getLevelState(){

	return this->levelState;
}

void GUI::setCursorList(const GUIElementList& cursor)
{
	//~ this->cursor = cursor;
}

void GUI::setEngineMode(engine::EngineMode engineMode)
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
	}
	
	if (!cursor->getActive() && cursor->getCharacter()) {
		state::Element* elementCursorNew = levelState.getElementList().getElement(cursor->getX(), cursor->getY());
		if (elementCursorNew && !((state::MobileElement*)elementCursorNew)->isPlayerCharacter()) {
			engine::AttackCommand* attack = new engine::AttackCommand(cursor->getCharacter(), elementCursorNew);
			engine.addCommand(attack);
			server.addCommand(attack);
	
		}
		if ((elementCursorNew == cursor->getCharacter() || elementCursorNew == 0 && cursor->getCharacter())){
			engine::MoveCommand* move = new engine::MoveCommand(cursor->getX(), cursor->getY(), cursor->getCharacter());
			cursor->setCharacter(0);
			engine.addCommand(move);
			engine.addCommand(move);

		}
	}
	if (engineMode) {
		engine::ModeCommand* engineModeCommand = new engine::ModeCommand(engineMode);
		engine.addCommand(engineModeCommand);
		engine.addCommand(engineModeCommand);
		engineMode = engine::PLAY;
	}
}

