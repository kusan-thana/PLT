#include "mobileElement.hpp"

/**
 * MobileElement Class
**/

using namespace state;

MobileElement::MobileElement() : speed(0), HP(0), attackPt(0), defensePt(0), nbAction(1), nbStep(0), level(1), 
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
