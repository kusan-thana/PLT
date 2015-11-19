#include "engine.hpp"
#include "ruler.hpp"
#include <iostream>
#include "actionList.hpp"
#include "incEpoch.hpp"

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
	//std::cout << "size : " << commandSet.size() << std::endl;
		if (levelState.getTurnToPlay() == state::PLAYER) {
			levelState.setTurnToPlay(state::OPPONENT);
		}
		else if (levelState.getTurnToPlay() == state::OPPONENT)
			levelState.setTurnToPlay(state::PLAYER);
	}
	commandSet.clear();
}

