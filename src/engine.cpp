#include "engine.hpp"
#include "ruler.hpp"
#include <iostream>
#include "actionList.hpp"

using namespace engine;


Engine::Engine(state::LevelState& levelState) : levelState(levelState) {

}


Engine::~Engine() {
}

void Engine::addCommand(Command *cmd) {
	commandSet.set(cmd);
}

void Engine::update(){

	Ruler ruler(this->commandSet, this->levelState);

	/*Appeler les methodes du Ruller pour verifier les commandes*/
	
	ruler.apply();
	commandSet.clear();

}
