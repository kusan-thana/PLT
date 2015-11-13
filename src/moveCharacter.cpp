#include "moveCharacter.hpp"
#include "element.hpp"
#include <iostream>

using namespace engine;

MoveCharacter::MoveCharacter(int idx) : idx(idx){
}
void MoveCharacter::setCoords(int dx, int dy, int dpos){
	
	this->dx = dx;
	this->dy = dy;
	this->dpos = dpos;
}
void MoveCharacter::setDirection(state::Direction next){
	
	this->newDirection = next;
	
}
void MoveCharacter::apply(state::LevelState& levelState){
	
	 state::Element* redTile = levelState.getElementCursors().getElement(0);
	redTile->setY((redTile->getY()+1)%32);
	//~ std::cout << "moveCharacter getX : " << redTile->getY() << std::endl;
	levelState.getElementCursors().notifyObservers(0);
}
