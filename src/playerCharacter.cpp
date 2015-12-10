#include <iostream>
#include "state.hpp"

/**
 * PlayerCharacter Class
**/
using namespace state;

PlayerCharacter::PlayerCharacter(TypeID IdElement) : mana(0) {

	this->IdElement = IdElement;
}
bool PlayerCharacter::isPlayerCharacter() const {
	
	return true;
}
Status PlayerCharacter::getStatus() const{
	
	return status;
}
Element* PlayerCharacter::clone() const{
	
	Element* clone = new PlayerCharacter(IdElement);
	
	((PlayerCharacter*)clone)->x = x;
	((PlayerCharacter*)clone)->y = y;
	((PlayerCharacter*)clone)->active = active;
	((PlayerCharacter*)clone)->orientation = orientation;
	
	((PlayerCharacter*)clone)->speed = this->speed;
	((PlayerCharacter*)clone)->HP = this->HP;
	((PlayerCharacter*)clone)->attackPt = this->attackPt;
	((PlayerCharacter*)clone)->defensePt = this->defensePt;
	((PlayerCharacter*)clone)->nbAction = this->nbAction;
	((PlayerCharacter*)clone)->nbStep = this->nbStep;
	((PlayerCharacter*)clone)->level = this->level;
	((PlayerCharacter*)clone)->experience = this->experience;
	((PlayerCharacter*)clone)->position = this->position;
	((PlayerCharacter*)clone)->turnPlayed = this->turnPlayed;
	((PlayerCharacter*)clone)->movePlayed = this->movePlayed;
	((PlayerCharacter*)clone)->status = this->status;
	
	((PlayerCharacter*)clone)->mana = this->mana;
	
	return clone;
}
