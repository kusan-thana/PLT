#include "guiMoveRange.hpp"
#include <iostream>
#include "guiTile.hpp"
#include "elementGrid.hpp"
#include "gui.hpp"
#include "element.hpp"
/**
 * GUIMoveRange Class
**/

using namespace gui;

GUIMoveRange::GUIMoveRange(GUI& gui) : GUIElementList(gui) {
}
void GUIMoveRange::setElement(state::Element* element){

	this->element = element;
}
int GUIMoveRange::getLength() const{
		
	return this->length;
}
void GUIMoveRange::setLength(int length){

	this->length = length;
}
void GUIMoveRange::computeRange(){
	
	state::ElementGrid grid = getGui().getLevelState().getElementGrid();
	int x = this->element->getX();
	int y = this->element->getY();
	guiElements.clear();

	for(int i=0; i<2*length+1; i++){
		for(int j=0; j<2*length+1; j++){
			
			if(x != i+(x-length) || y != j+(y-length))
				guiElements.push_back(new GUITile(i+(x-length),j+(y-length)));	//Square formation around the element
		}
	}
}
void GUIMoveRange::clear(){
	
	guiElements.clear();
}
