#include <iostream>
#include "state.hpp"

/**
 * Monster Class
**/
using namespace state;

Monster::Monster(TypeID IdElement) {

	this->IdElement = IdElement;
}
bool Monster::isPlayerCharacter() const {

	return false;
}
Status Monster::getStatus() const{
	
	return status;
}
Element* Monster::clone() const{
	
	Element* clone = new Monster(IdElement);
	
	((Monster*)clone)->x = x;
	((Monster*)clone)->y = y;
	((Monster*)clone)->active = active;
	((Monster*)clone)->orientation = orientation;
	
	((Monster*)clone)->speed = this->speed;
	((Monster*)clone)->HP = this->HP;
	((Monster*)clone)->attackPt = this->attackPt;
	((Monster*)clone)->defensePt = this->defensePt;
	((Monster*)clone)->nbAction = this->nbAction;
	((Monster*)clone)->nbStep = this->nbStep;
	((Monster*)clone)->level = this->level;
	((Monster*)clone)->experience = this->experience;
	((Monster*)clone)->position = this->position;
	((Monster*)clone)->turnPlayed = this->turnPlayed;
	((Monster*)clone)->movePlayed = this->movePlayed;
	((Monster*)clone)->status = this->status;
	
	return clone;
}
