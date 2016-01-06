#include "server.hpp"
#include <iostream>
using namespace server;

RemoteServerSFML::RemoteServerSFML(){
}
RemoteServerSFML::~RemoteServerSFML(){
}
void RemoteServerSFML::run(){

	while(!quit)
	{
		if(levelState.getTurnToPlay() == state::PLAYER) {
			if (iaAutoMode) {
				//dumbAI.run(engine);
			}
		}
		else if (levelState.getTurnToPlay() == state::OPPONENT) {
		}

		engine.update();
	}
}
