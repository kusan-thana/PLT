#include "gui.hpp"

using namespace gui;

GUIObservable::GUIObservable()
{
}


GUIObservable::~GUIObservable()
{
}


void GUIObservable::registerObserver(GUIObserver* o) {

	observers.push_back(o);
}
void GUIObservable::unregisterObserver(GUIObserver* o) {

}
void GUIObservable::notifyObservers(const GUIEvent& e) {

	for(std::vector<GUIObserver*>::iterator observer = observers.begin(); observer != observers.end(); observer++)
	{
		(*observer)->guiChanged(e);
	}
}

