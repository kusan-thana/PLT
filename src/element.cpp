#include "element.hpp"

/**
 * Element Class
**/

using namespace state;

Element::Element() : x(0), y(0), IDElement(SPACE), orientation(NONE), active(false){
}
Element::~Element(){
}

int Element::getX() const{
	
	return this->x;
}
int Element::getY() const{
	
	return this->y;
}
TypeID Element::getTypeID() const{
	
	return this->IDElement;
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
void Element::setDirection(state::Direction orientation){
	
	this->orientation = orientation;
}
bool Element::isActive() const{
	
	return active;
}
