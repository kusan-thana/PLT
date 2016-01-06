#include "engine.hpp"
#include <iostream>
/**
 * IncEpoch Class
**/

using namespace engine;

IncEpoch::IncEpoch(){
}
void IncEpoch::apply(state::LevelState& levelState){
	//std::cout << "Epoch : " << levelState.getEpoch() << std::endl;
	levelState.setEpoch(levelState.getEpoch()+1);
}


void IncEpoch::undo(state::LevelState& levelState) {
	
}

