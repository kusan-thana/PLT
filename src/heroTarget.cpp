#include "heroTarget.hpp"
#include <iostream>


/**
 * HeroTarget Class
**/

using namespace ai;

bool HeroTarget::isTarget(int x, int y, const state::Element* e) const{

	if(e->getTypeID() == state::HERO && x == e->getX() && y == e->getY()){
		
		return true;
	}
	else return false;
}
