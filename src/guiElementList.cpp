#include "guiElementList.hpp"
#include "gui.hpp"
#include "levelState.hpp"
#include "guiEvent.hpp"
#include "elementList.hpp"
#include "mobileElement.hpp"
#include <iostream>
/**
 * guiElementList Class
**/

using namespace gui;

GUIElementList::GUIElementList(GUI& gui): gui(gui){
}
GUI& GUIElementList::getGui() {
	
	return gui;
}
int GUIElementList::size() const{

	return guiElements.size();
}
GUIElement* GUIElementList::getGuiElement(int i) const{

	return guiElements[i];
}
GUIElement* GUIElementList::getGuiElement(int x, int y) const{

	for(int i=0; i<size(); i++){
		
		if(x == guiElements[i]->getX() && y == guiElements[i]->getY())
			return guiElements[i];
	}
	return 0;
}
void GUIElementList::setGuiElement(int i, GUIElement* guiElement){

	std::vector<GUIElement*>::iterator it = guiElements.begin();
	guiElements.insert (it+i,guiElement);
}
void GUIElementList::notifyObservers(int i) {
	
	GUIEvent guiEvent(*this,i);
	GUIObservable::notifyObservers(guiEvent);
}
void GUIElementList::update(){
	
	state::ElementList characters = getGui().getLevelState().getElementList();
	int size = characters.size();
	
	for(int i=0; i<size; i++){
		if(getGuiElement(i)->getGuiTypeId() == ACTIVE_TILE){
			state::MobileElement* element = (state::MobileElement*)characters.getElement(i);
			if(!element->getTurnPlayed())
			{
				int x = element->getX();
				int y = element->getY();
				
				//~ tileList.setGuiElement(0, new gui::GUITile(x,y,gui::GUITypeId::ACTIVE_TILE));
			}
		}
	}
}
