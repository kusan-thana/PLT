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
	/*Appeler les methodes du Ruller pour verifier les commandes*/

		ruler.apply();
			
		//Gestion des tours
		state::ElementList& elementList = levelState.getElementList();
	
		if (levelState.getTurnToPlay() == state::PLAYER) {
			for(int i = 0, count = 0; i < levelState.getElementList().size();i++){
				if(((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter()) //Si c'est un personnage
					if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed()){ //Si ce personnage a joué
						count++;
						if (count == elementList.numberOfPlayer()){ //Si l'ensemble des personnage a joué - Opponent turn
							for(int i = 0, count = 0; i < levelState.getElementList().size();i++){
								if(!((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter())
									((state::MobileElement*)(elementList.getElement(i)))->setTurnPlayed(false); //Reinitialization - ce element peut jouer a nouveau
								}
							levelState.setTurnToPlay(state::OPPONENT); //Opponent turn
						
						}
					}
			}
		}
		else if (levelState.getTurnToPlay() == state::OPPONENT) {
			for(int i = 0, count = 0; i < levelState.getElementList().size();i++){
				if(!((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter()) //Si c'est un personnage
					if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed()){ //Si ce personnage a joué
						count++;
						if (count == elementList.numberOfMonster()){ //Si l'ensemble des personnage a joué - Opponent turn
							for(int i = 0, count = 0; i < levelState.getElementList().size();i++){
								if(((state::MobileElement*)(elementList.getElement(i)))->isPlayerCharacter())
									((state::MobileElement*)(elementList.getElement(i)))->setTurnPlayed(false); //Reinitialization - ce element peut jouer a nouveau
								}
							levelState.setTurnToPlay(state::PLAYER); //Opponent turn
						}
					}
			}
		}
	}
	commandSet.clear();
}

