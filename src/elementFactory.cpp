#include "elementFactory.hpp"

/**
 * ElementFactory Class
**/
using namespace state;

Element* const ElementFactory::newInstance(char id){
	
	return ( list[id]->newInstance() );
}
void ElementFactory::registerType(char id, AElementAlloc* a){
	
	list[id] = a;
}
