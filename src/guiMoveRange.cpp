#include <iostream>
#include "gui.hpp"
#include "elementGrid.hpp"
#include "gui.hpp"
#include "element.hpp"
#include "mobileElement.hpp"
/**
 * GUIMoveRange Class
**/

using namespace gui;

GUIMoveRange::GUIMoveRange(GUI& gui) : GUIElementList(gui) {
}
void GUIMoveRange::setElement(state::Element* element){

	this->element = element;
}
void GUIMoveRange::computeRange(){

	int x = this->element->getX();
	int y = this->element->getY();
	int length = ((state::MobileElement*)element)->getNbStep();
	guiElements.clear();

	for(int i=0; i<2*length+1; i++){
		for(int j=0; j<2*length+1; j++){
			
			if(x != i+(x-length) || y != j+(y-length))
				guiElements.push_back(new GUITile(i+(x-length),j+(y-length), MOVE_RANGE));	//Square formation around the element
		}
	}
}

