#include "elementList.hpp"
#include "levelState.hpp"
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
void ElementList::setElementFactory(state::ElementFactory* factory){

	this->factory = factory;
}
void ElementList::setElement(int i, state::Element* element){

	std::vector<state::Element*>::iterator it = elements.begin();
	elements.insert (it+i,element);
}
