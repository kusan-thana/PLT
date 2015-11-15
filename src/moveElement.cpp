#include "MoveElement.hpp"
#include "element.hpp"
#include <iostream>


using namespace engine;

MoveElement::MoveElement(state::Element* tile) : dx(0), dy(0), tile(tile){
}

MoveElement::MoveElement(engine::MoveElement* moveElement){
	this->dx = moveElement->dx;
	this->dy = moveElement->dy;
	this->tile = moveElement->tile;

}

void MoveElement::setCoords(int dx, int dy){
	
	this->dx = dx;
	this->dy = dy;
}
void MoveElement::apply(state::LevelState& levelState){
	
	tile->setX((tile->getX()+dx)%16);
	tile->setY((tile->getY()+dy)%32);
	//~ std::cout << "moveCharacter getX : " << redTile->getY() << std::endl;
	levelState.getElementCursors().notifyObservers(-1);
	levelState.getElementList().notifyObservers(-1);

}

void MoveElement::setTile(state::Element* tile) {
	this->tile = tile;
}

