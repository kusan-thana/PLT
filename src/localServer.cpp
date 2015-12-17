#include "server.hpp"
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
		if (levelState.getTurnToPlay() == state::OPPONENT) {
			ais->run(engine);
		}
		engine.update();
	}
}
