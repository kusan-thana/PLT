#include "engine.hpp"
#include "ruler.hpp"
#include <iostream>

using namespace engine;

Engine::Engine() {


}


Engine::~Engine() {
}

void Engine::addCommand(Command *cmd) {
	commandSet.set(cmd);
}

void Engine::update(){

	Ruler ruler(this->commandSet, this->levelState);
	//std::cout << "benoit";
	
	
	/*Appeler les methodes du Ruller pour verifier les commandes*/
	
	
	
	ruler.apply();	
}
