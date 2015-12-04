#include "element.hpp"

/**
 * Element Class
**/

using namespace state;

Element::Element() : x(0), y(0), IdElement(SPACE), orientation(NONE), active(false){
}
Element::~Element(){
	
	delete(this);
}
int Element::getX() const{
	
	return this->x;
}
int Element::getY() const{
	
	return this->y;
}
TypeId Element::getTypeId() const{
	
	return this->IdElement;
}
bool Element::equals(const Element& other) const{
	
	if(this->x == other.x && this->y == other.y && this->IdElement == other.IdElement && this->orientation == orientation){
	
		return true;
	}
	else return false;
}
state::Direction Element::getDirection() const{
	
	return this->orientation;
}
void Element::setX(int x){
	
	this->x = x;
}
void Element::setY(int y){
	
	this->y = y;
}
void Element::setActive(bool active) {

	this->active = active;
}
void Element::setDirection(state::Direction orientation){
	
	this->orientation = orientation;
}
bool Element::isActive() const{
	
	return active;
}
