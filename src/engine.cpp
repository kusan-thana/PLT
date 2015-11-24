#include "engine.hpp"
#include "ruler.hpp"
#include <iostream>
#include "actionList.hpp"
#include "incEpoch.hpp"
#include "mobileElement.hpp"
#include "elementList.hpp"

using namespace engine;


Engine::Engine(state::LevelState& levelState) : levelState(levelState), actions(levelState) {

}


Engine::~Engine() {
}

void Engine::addCommand(Command *cmd) {
	commandSet.set(cmd);
}
void Engine::setMode(EngineMode mode) {
	enginemode = mode;
}
EngineMode Engine::getMode() {
	return enginemode;
}
void Engine::update() {
	


	Ruler ruler(this->actions, this->commandSet, this->levelState);
	if (commandSet.size()) {
		actions.add(new IncEpoch());
	/*Appeler les methodes du Ruller pour verifier les commandes*/

		ruler.apply();
			
	//Gestion des tours
	state::ElementList& elementList = levelState.getElementList();
	
		if (levelState.getTurnToPlay() == state::PLAYER) {
			levelState.setTurnToPlay(state::OPPONENT);
			for(int i = 0; i < levelState.getElementList().size();i++){
				if(((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter())
					if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed() == false)
						levelState.setTurnToPlay(state::PLAYER);
			}
			
		}
		else if (levelState.getTurnToPlay() == state::OPPONENT){
			levelState.setTurnToPlay(state::PLAYER);
			for(int i = 0; i < levelState.getElementList().size();i++){
				if(((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter())
					((state::MobileElement*)(elementList.getElement(i)))->setTurnPlayed(false) ;
			}
			for(int i = 3; i < levelState.getElementList().size();i++){
				if(!((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter())
					if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed() == false){
						levelState.setTurnToPlay(state::OPPONENT);

					}			
			}	
		}	
	}
	commandSet.clear();
}

