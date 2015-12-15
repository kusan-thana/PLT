#include "server.hpp"

using namespace server;

LocalServer::LocalServer(){

	this->ais = new ai::HeuristicAI(engine.getLevelState());
}


LocalServer::~LocalServer(){

}

void LocalServer::run(){
	
}
