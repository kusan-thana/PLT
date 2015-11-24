#include "mobileElement.hpp"

/**
 * MobileElement Class
**/

using namespace state;

MobileElement::MobileElement() : speed(0), HP(100), attackPt(5), defensePt(0), nbAction(1), nbStep(2), level(1), 
								 experience(0), position(0), turnPlayed(false), selected(false), status(NORMAL){
}
bool MobileElement::isStatic() const{
	
	return false;
}
int MobileElement::getNbStep() const{
	
	return nbStep;
}
int MobileElement::getNbAction() const{

	return nbAction;
}
void MobileElement::setNbAction(int nbAction){
	
	this->nbAction = nbAction;
}
bool MobileElement::isSelected(){

	return selected;
}
bool MobileElement::getTurnPlayed() const{
	return turnPlayed;
}
void MobileElement::setTurnPlayed(bool turnPlayed){
	this->turnPlayed = turnPlayed;
}
