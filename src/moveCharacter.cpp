#include "moveCharacter.hpp"
#include "mobileElement.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace engine;

MoveCharacter::MoveCharacter(state::Element* character,int x, int y, state::LevelState& levelState) : character(character), x(x), y(y), levelState(levelState)
{
}
MoveCharacter::~MoveCharacter()
{
}
void MoveCharacter::apply(state::LevelState& levelState) {
	
	((state::MobileElement*)character)->setTurnPlayed(true);
	character->setX(x);
	character->setY(y);
	levelState.getElementList().notifyObservers(levelState.getElementList().getIdxElement(character));
	
}


