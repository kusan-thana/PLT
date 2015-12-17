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

	// while(1){
		//~ std::cout << "localServer running\n";
	// }
	while(!quit)
	{
		mutex.lock();
		engine.update();
		mutex.unlock();
	}
}
