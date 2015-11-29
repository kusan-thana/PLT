#include <iostream>
#include "playerCharacter.hpp"

/**
 * PlayerCharacter Class
**/
using namespace state;

PlayerCharacter::PlayerCharacter(TypeId IdElement) : mana(0) {

	this->IdElement = IdElement;
}
bool PlayerCharacter::isPlayerCharacter() const {
	
	return true;
}
Status PlayerCharacter::getStatus() const{
	
	return status;
}
