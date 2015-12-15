#include "server.hpp"
#include <iostream>

using namespace server;

LocalServer::LocalServer(){

	this->ais = new ai::HeuristicAI(engine.getLevelState());
}


LocalServer::~LocalServer(){

}

void LocalServer::run(){

	//~ while(1){
		std::cout << "localServer running\n";
	//~ }

	if (engine.getLevelState().getTurnToPlay() == state::OPPONENT) {
		((ai::HeuristicAI*)ais)->run(engine);
	}
	//~ else if(levelState.getTurnToPlay() == state::PLAYER) {
		//~ if(gui.getStartPlayerAI()){
			//~ heuristicAi.run(engine);

		//~ }	
	//~ }
	engine.update();
}
