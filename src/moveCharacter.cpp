#include "moveCharacter.hpp"

#include <iostream>
using namespace engine;

MoveCharacter::MoveCharacter(state::Element* character,int x, int y, state::LevelState& levelState) : character(character), x(x), y(y), levelState(levelState)
{
}


MoveCharacter::~MoveCharacter()
{
}


void MoveCharacter::apply(state::LevelState& levelState) {

	character->setX(x);
	character->setY(y);
	levelState.getElementList().notifyObservers(-1);
	std::cout << "benoit" << std::endl;
}


