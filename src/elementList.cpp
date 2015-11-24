#include "elementList.hpp"

#include "levelState.hpp"
#include "levelListEvent.hpp"
#include <iostream>
/**
 * ElementList Class
**/

using namespace state;

ElementList::ElementList(LevelState& levelState): levelState(levelState){
}
const LevelState& ElementList::getLevelState() const{
	
	return levelState;
}
int ElementList::size() const{

	return elements.size();
}
Element* ElementList::getElement(int i) const{

	return elements[i];
}
Element* ElementList::getElement(int x, int y) const{

	for(int i=0; i<size(); i++){
		
		if(x == elements[i]->getX() && y == elements[i]->getY())
			return elements[i];
	}
	return 0;
}
void ElementList::setElementFactory(state::ElementFactory* factory){

	this->factory = factory;
}
void ElementList::setElement(int i, state::Element* element){

	std::vector<state::Element*>::iterator it = elements.begin();
	elements.insert (it+i,element);
}
void ElementList::notifyObservers(int i) {
	
	LevelListEvent levelListEvent(*this,i);
	Observable::notifyObservers(levelListEvent);
}

		
