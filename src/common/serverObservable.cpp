#include "server.hpp"
#include <iostream>
/**
 * Observable Class
**/

using namespace server;

Observable::~Observable(){

	observers.clear();
}
void Observable::registerObserver(ServerObserver* o) {

	observers.push_back(o);
}
void Observable::notifyObservers(const ServerEvent& e) {
	
	for(std::vector<ServerObserver*>::iterator observer = observers.begin(); observer != observers.end(); observer++)
	{
		(*observer)->serverChanged(e);
	}
}

