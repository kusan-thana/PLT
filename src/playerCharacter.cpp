#include <iostream>
#include "playerCharacter.hpp"

/**
 * PlayerCharacter Class
**/

PlayerCharacter::PlayerCharacter(TypeID IDElement) : mana(0), selected(false), status(DEAD) {
	//Need to look after "TypeID" argument to initialize "Element" class...
}
bool PlayerCharacter::isPlayerCharacter() {
	
	return true;
}
void PlayerCharacter::doAction(MobileElement& target, TypeAction action){
	
	switch(IDElement){
		case HERO:
			switch(action){
				case PUNCH:
					//Need to be defined
					break;
				case SWORDSTRIKE:
					//Need to be defined
					break;
			}
			break;
		case BRUTE:
			switch(action){
				case PUNCH:
					//Need to be defined
					break;
				case HAMMERSTRIKE:
					//Need to be defined
					break;
			}
			break;
		case HEALER:
			switch(action){
				case PUNCH:
					//Need to be defined
					break;
				case HEAL:
					//Need to be defined
					break;
			}
			break;
		case WIZARD:
			switch(action){
				case PUNCH:
					//Need to be defined
					break;
				case FIREBALL:
					//Need to be defined
					break;
				}
			break;
	}
	
}
Status PlayerCharacter::getStatus() const{
	
	return status;
}
bool PlayerCharacter::isSelected(){

	return selected;
}
