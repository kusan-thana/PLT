#include "server.hpp"

using namespace server;

Server::Server() : engine(levelState),quit(false){	
	
}
Server::~Server(){

}
engine::Engine& Server::getEngine(){
	
	return engine;
}
state::LevelState& Server::getLevelState(){

	return levelState;
}
void Server::runBackground (){
	
	mainThread = new std::thread(&Server::run, this);
}
void Server::join (){
	quit = true;
	mainThread->join();
	//~ mainThread->detach();
}
