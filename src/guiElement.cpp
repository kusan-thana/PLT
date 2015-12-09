#include "gui.hpp"

/**
 * GUIElement Class
**/

using namespace gui;

GUIElement::GUIElement() : x(0), y(0), active(false){
}
GUIElement::~GUIElement(){
}
int GUIElement::getX() const{
	
	return this->x;
}
int GUIElement::getY() const{
	
	return this->y;
}
bool GUIElement::getActive() const{
	
	return this->active;
}
void GUIElement::setX(int x){
	
	this->x = x;
}
void GUIElement::setY(int y){
	
	this->y = y;
}
void GUIElement::setActive(bool active) {

	this->active = active;
}

