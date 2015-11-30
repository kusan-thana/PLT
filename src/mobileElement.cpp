#include "mobileElement.hpp"

/**
 * MobileElement Class
**/

using namespace state;

MobileElement::MobileElement() : speed(0), HP(5), attackPt(5), defensePt(0), nbAction(1), nbStep(2), level(1), 
								 experience(0), position(0), turnPlayed(false), movePlayed(false), status(NORMAL){
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
void state::MobileElement::setHP(int HP)
{
	this->HP = HP;
}
int state::MobileElement::getAttackPt() const
{
	return attackPt;
}
void state::MobileElement::setAttackPt(int attackPt)
{
	this->attackPt = attackPt;
}
int state::MobileElement::getDefensePt() const
{
	return defensePt;
}
void state::MobileElement::setDefensePt(int defensePt)
{
	this->defensePt = defensePt;
}
void state::MobileElement::setMovePlayed(bool movePlayed)
{
	this->movePlayed = movePlayed;
}
bool state::MobileElement::getMovePlayed() const
{
	return movePlayed;
}
int state::MobileElement::getHP() const
{
	return HP;
}
bool MobileElement::getTurnPlayed() const{
	return turnPlayed;
}
void MobileElement::setTurnPlayed(bool turnPlayed){
	this->turnPlayed = turnPlayed;
}

