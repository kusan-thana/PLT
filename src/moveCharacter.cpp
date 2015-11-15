#include "moveCharacter.hpp"
#include "element.hpp"
#include <iostream>


using namespace engine;

MoveCharacter::MoveCharacter(int idx) : idx(idx), dx(0), dy(0), dpos(0){
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
	redTile->setX((redTile->getX()+dx)%16);
	redTile->setY((redTile->getY()+dy)%32);
	//~ std::cout << "moveCharacter getX : " << redTile->getY() << std::endl;
	levelState.getElementCursors().notifyObservers(-1);
}
