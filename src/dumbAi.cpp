#include "dumbAi.hpp"
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
	int x = mainLevelState.getElementList().getElement(1)->getX();
	int y = mainLevelState.getElementList().getElement(1)->getY();

	if (x > mainLevelState.getElementList().getElement(0)->getX())
		x--;
	else if (x < mainLevelState.getElementList().getElement(0)->getX())
		x++;
	if (y > mainLevelState.getElementList().getElement(0)->getY())
		y--;
	else if (y < mainLevelState.getElementList().getElement(0)->getY())
		y++;
	engine::MoveCommand* move = new engine::MoveCommand(x, y, mainLevelState.getElementList().getElement(1));
	//std::cout << move->getTypeId() << std::endl;
	engine.addCommand(move);

}
