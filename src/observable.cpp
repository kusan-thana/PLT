#include "observable.hpp"
#include "levelStateEvent.hpp"
#include <iostream>
/**
 * Observable Class
**/

using namespace state;

void Observable::registerObserver(LevelStateObserver* o){

	observers.push_back(o);
}
void Observable::notifyObservers(const LevelStateEvent& e){
	
	for(std::vector<LevelStateObserver*>::iterator observer = observers.begin(); observer != observers.end(); observer++)
	{
		(*observer)->levelStateChanged(e);
	}
}
