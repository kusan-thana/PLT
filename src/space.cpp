#include "state.hpp"

/**
 * Space Class
**/

using namespace state;

Space::Space(SpaceTypeID id) : IDSpace(id){
	
	this->IdElement = SPACE;
}
bool Space::isSpace() const{
	
	return false;
}
SpaceTypeID Space::getSpaceTypeID() const{
	
	return this->IDSpace;
}
void Space::setSpaceTypeID(SpaceTypeID id){

	this->IDSpace = id;
}
Element* Space::clone() const{
	
	Element* clone = new Space(IDSpace);
	
	((Space*)clone)->IdElement = IdElement;
	((Space*)clone)->x = x;
	((Space*)clone)->y = y;
	((Space*)clone)->active = active;
	((Space*)clone)->orientation = orientation;
	
	return clone;
}
