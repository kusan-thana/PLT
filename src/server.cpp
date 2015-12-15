#include "server.hpp"

using namespace server;

Server::Server() : engine(levelState){	
	
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

	mainThread->join();
	//~ mainThread->detach();
}
