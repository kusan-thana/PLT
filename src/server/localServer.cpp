#include "../common/server.hpp"
#include <iostream>
#include <mutex>
using namespace server;

LocalServer::LocalServer(){

	this->ais = new ai::HeuristicAI(engine.getLevelState());
}
LocalServer::~LocalServer(){
}
void LocalServer::run(){

	while(!quit)
	{
		if(levelState.getTurnToPlay() == state::PLAYER) {
			if (iaAutoMode) {
				ais->run(engine, *this);
				//dumbAI.run(engine);
			}
		}
		else if (levelState.getTurnToPlay() == state::OPPONENT) {
			ais->run(engine, *this);
		}

		engine.update();
	}
	
}

void LocalServer::addCommand(engine::Command *cmd) {
	commandSet->set(cmd);
}

