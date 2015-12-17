#include "engine.hpp"
#include <iostream>

using namespace engine;


Engine::Engine(state::LevelState& levelState) : levelState(levelState), actions(levelState), engineMode(PLAY) {
	
	commandSet = new engine::CommandSet();
}


Engine::~Engine() {
	free(commandSet);
}

void Engine::addCommand(Command *cmd) {
	commandSet->set(cmd);
}
void Engine::setMode(EngineMode mode) {
	engineMode = mode;
}
state::LevelState& Engine::getLevelState() const{

	return this->levelState;
}
EngineMode Engine::getMode() {
	return engineMode;
}
void Engine::update() {
	Ruler ruler(this->actions, *commandSet, this->levelState);
	if (commandSet->size()) {
		if (commandSet->get(MODE)) {

			setMode(((ModeCommand*)commandSet->get(MODE))->getMode());
		}
		if (engineMode == PLAY){

			//MODIFICATION ETAT
			update_mutex.lock();
			ruler.apply();
			update_mutex.unlock();
			//FIN MODIFICATION ETAT

			turnGestion();
			
			//MODIFICATION ETAT
			update_mutex.lock();
			actions.apply();
			update_mutex.unlock();
			//FIN MODIFICATION ETAT
			
			actions.clear();

		}
		else if (engineMode == SAVE){
			levelStateSave =levelState.clone();	
			engineMode = PLAY;
		}
		else if (engineMode == LOADSAVE) {
			levelState.copy(*levelStateSave);

			levelState.getElementList().notifyObservers(-1);
			levelState.getElementGrid().notifyObservers(-1,-1);
			engineMode = PLAY;
		}
		else if (engineMode == ROLLBACK) {
			engineMode = PLAY;
		}
		commandSet->clear();
	}
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
						actions.add(new EndTeamTurn(state::PLAYER));
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
						actions.add(new EndTeamTurn(state::OPPONENT));
					}
				}
			}
		}
	}
}
std::mutex& Engine::getUpdateMutex() const{
		
	return update_mutex;
}

