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

