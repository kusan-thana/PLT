#include "guiTile.hpp"
#include <iostream>
/**
 * GUITile Class
**/

using namespace gui;

GUITile::GUITile(int x, int y) {
	
	this->x = x;	//Argument from GUIElementList
	this->y = y;
}
GUITypeId GUITile::getGuiTypeId() const{
	
	return TILE;
}
