#include "space.hpp"

/**
 * Space Class
**/

using namespace state;

Space::Space(SpaceTypeID id) : IDSpace(id){
	
	this->IDElement = SPACE;
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
