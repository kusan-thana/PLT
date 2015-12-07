#include "engine.hpp"
#include "ruler.hpp"
#include <iostream>
#include "actionList.hpp"
#include "incEpoch.hpp"
#include "mobileElement.hpp"
#include "elementList.hpp"
#include "modeCommand.hpp"
using namespace engine;


Engine::Engine(state::LevelState& levelState) : levelState(levelState), actions(levelState) {

}


Engine::~Engine() {
}

void Engine::addCommand(Command *cmd) {
	commandSet.set(cmd);
}
void Engine::setMode(EngineMode mode) {
	engineMode = mode;
}
EngineMode Engine::getMode() {
	return engineMode;
}
void Engine::update() {
	
	
	Ruler ruler(this->actions, this->commandSet, this->levelState);
	if (commandSet.size()) {
		if (commandSet.get(MODE)) {
			setMode(((ModeCommand*)commandSet.get(MODE))->getMode());
		}
		if (engineMode == PLAY){
			ruler.apply();
			turnGestion();
		}
		else if (engineMode == SAVE){
			levelStateSave =levelState.clone();	
			engineMode = PLAY;
		}
		else if (engineMode == LOADSAVE) {
			levelState.copy(*levelStateSave);
			levelState.getElementList().notifyObservers(-1);
			levelState.getElementGrid().notifyObservers(-1,-1);
		}
		else if (engineMode == ROLLBACK) {
			
			engineMode = PLAY;
		}
	}
	commandSet.clear();
}
void Engine::turnGestion() {
	
	//Gestion des tours
	state::ElementList& elementList = levelState.getElementList();
		
	if (levelState.getTurnToPlay() == state::PLAYER) {
		for(int i = 0, count = 0; i < levelState.getElementList().size();i++){
			state::MobileElement* curr_mobileElement = (state::MobileElement*)elementList.getElement(i);
			if(curr_mobileElement->isPlayerCharacter()){ //Si c'est un personnage
				if (curr_mobileElement->getTurnPlayed()){ //Si ce personnage a joué
					count++;
					if (count == elementList.numberOfPlayer()){ //Si l'ensemble des personnage a joué - Opponent turn
						levelState.setTurnToPlay(state::OPPONENT); //Opponent turn
						for(int j = 0, count = 0; j < elementList.size();j++){
							if(curr_mobileElement->isPlayerCharacter()){
								((state::MobileElement*)(elementList.getElement(j)))->setTurnPlayed(false); //Reinitialization - ce element peut jouer a nouveau
								((state::MobileElement*)(elementList.getElement(j)))->setMovePlayed(false); //Reinitialization - ce element peut jouer a nouveau
								levelState.getElementList().notifyObservers(j);
							}
						}			
					}
				}
			}
		}
	}
	else if (levelState.getTurnToPlay() == state::OPPONENT) {
		for(int i = 0, count = 0; i < levelState.getElementList().size();i++){
			state::MobileElement* curr_mobileElement = (state::MobileElement*)elementList.getElement(i);
			if(!curr_mobileElement->isPlayerCharacter()){ //Si c'est un personnage
				if (curr_mobileElement->getTurnPlayed()){ //Si ce personnage a joué
					count++;
					if (count == elementList.numberOfMonster()){ //Si l'ensemble des personnage a joué - Player turn

						levelState.setTurnToPlay(state::PLAYER); //Player turn
						for(int j = 0, count = 0; j < elementList.size();j++){
							if(!((state::MobileElement*)(elementList.getElement(j)))->isPlayerCharacter()){
								((state::MobileElement*)(elementList.getElement(j)))->setTurnPlayed(false); //Reinitialization - ce element peut jouer a nouveau
								((state::MobileElement*)(elementList.getElement(j)))->setMovePlayed(false); //Reinitialization - ce element peut jouer a nouveau
								levelState.getElementList().notifyObservers(j);
							}
						}	
					}
				}
			}
		}
	}
}


