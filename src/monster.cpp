#include <iostream>
#include "monster.hpp"

/**
 * Monster Class
**/
using namespace state;

Monster::Monster(TypeID IDElement) {

	this->IDElement = IDElement;
}
bool Monster::isPlayerCharacter() const {
	//std::cout << "here";
	return false;
}
void Monster::doAction(MobileElement& target, TypeAction action){
	
	switch(IDElement){
		case MINION:
			switch(action){
				case BITE:
					//Need to be defined
				break;
				case SCRATCH:
					//Need to be defined
				break;
			}
			break;
		case BOSS:
			switch(action){
				case PUNCH:
					//Need to be defined
				break;
				case POISON:
					//Need to be defined
				break;
			}
			break;
	}
}
Status Monster::getStatus() const{
	
	return status;
}

