#include "guiMoveRange.hpp"
#include <iostream>
#include "guiTile.hpp"
/**
 * GUIMoveRange Class
**/

using namespace gui;

GUIMoveRange::GUIMoveRange(GUI& gui, int length, state::Element* element) : GUIElementList(gui), length(length) {
	
	int x = element->getX();
	int y = element->getY();

	for(int i=x-length; i<2*length+1; i++){
		for(int j=y-length; j<2*length+1; j++){
		
			guiElements.push_back(new GUITile(i,j));	//Square formation around the element
		}
	}
}
int GUIMoveRange::getLength() const{
	
	return this->length;
}
void GUIMoveRange::setLength(int length){
	
	this->length = length;
}
