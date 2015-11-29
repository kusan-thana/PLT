#include <iostream>
#include "monster.hpp"

/**
 * Monster Class
**/
using namespace state;

Monster::Monster(TypeId IdElement) {

	this->IdElement = IdElement;
}
bool Monster::isPlayerCharacter() const {

	return false;
}
Status Monster::getStatus() const{
	
	return status;
}

