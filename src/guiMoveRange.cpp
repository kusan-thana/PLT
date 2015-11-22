#include "guiMoveRange.hpp"
#include <iostream>
#include "guiTile.hpp"
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
	
	int x = this->element->getX();
	int y = this->element->getY();
	//~ std::cout << "x " << x << std::endl;
	//~ std::cout << "y " << y << std::endl;
	//~ std::cout << "llength " << length << std::endl;

	for(int i=x-length; i<2*length+1; i++){
		for(int j=y-length; j<2*length+1; j++){
		
			guiElements.push_back(new GUITile(i,j));	//Square formation around the element
			//~ std::cout << "test " << std::endl;
		}
	}
	//~ std::cout << "size " << size() << std::endl;
}
