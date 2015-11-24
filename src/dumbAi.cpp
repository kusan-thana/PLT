#include "dumbAi.hpp"
#include "elementList.hpp"
#include "mobileElement.hpp"
#include <iostream>

/**
 * DumbAI Class
**/

using namespace ai;

DumbAI::DumbAI(const state::LevelState& mainLevelState) : AI(mainLevelState){
}
void DumbAI::dumbMove(int idx, engine::CommandSet& commands){
}
void DumbAI::run(engine::Engine& engine){
	//std::cout << mainLevelState.getElementList().getElement(0) << std::endl;
	
	state::ElementList elementList = mainLevelState.getElementList();
	int x_hero = elementList.getElement(0)->getX();
	int y_hero = elementList.getElement(0)->getY();
	
	for (int i = 3; i < elementList.size(); i++){
		if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed() == false){
			int x = elementList.getElement(i)->getX();
			int y = elementList.getElement(i)->getY();
			
			//if (x > x_hero)
			//	x--;
			//else if (x < x_hero)
			//	x++;
			if (y > y_hero)
				y--;
			else if (y < y_hero)
				y++;
			engine::MoveCommand* move = new engine::MoveCommand(x, y, mainLevelState.getElementList().getElement(i));
			//std::cout << move->getTypeId() << std::endl;
			engine.addCommand(move);	
		}	
	}

}
