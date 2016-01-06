#include "gui.hpp"
#include <iostream>
/**
 * GUITile Class
**/

using namespace gui;

GUITile::GUITile(int x, int y, GUITypeId guiTypeId) {
	
	this->x = x;	//Argument from GUIElementList
	this->y = y;
	this->guiTypeId = guiTypeId;
}
GUITypeId GUITile::getGuiTypeId() const{
	
	return guiTypeId;
}

