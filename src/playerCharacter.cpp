#include <iostream>
#include "playerCharacter.hpp"

/**
 * PlayerCharacter Class
**/
using namespace state;

PlayerCharacter::PlayerCharacter(TypeID IDElement) : mana(0) {

	this->IDElement = IDElement;
}
bool PlayerCharacter::isPlayerCharacter() const {
	
	return true;
}
void PlayerCharacter::doAction(MobileElement& target, TypeAction action){
	
	switch(IDElement){
		case HERO:
			switch(action){
				case TypeAction::PUNCH:
					//Need to be defined
				break;
				case TypeAction::SWORDSTRIKE:
					//Need to be defined
				break;
			}
			break;
		case BRUTE:
			switch(action){
				case TypeAction::PUNCH:
					//Need to be defined
				break;
				case TypeAction::HAMMERSTRIKE:
					//Need to be defined
				break;
			}
			break;
		case HEALER:
			switch(action){
				case TypeAction::PUNCH:
					//Need to be defined
				break;
				case TypeAction::HEAL:
					//Need to be defined
				break;
			}
			break;
		case WIZARD:
			switch(action){
				case TypeAction::PUNCH:
					//Need to be defined
				break;
				case TypeAction::FIREBALL:
					//Need to be defined
				break;
				}
			break;
	}
}
Status PlayerCharacter::getStatus() const{
	
	return status;
}
