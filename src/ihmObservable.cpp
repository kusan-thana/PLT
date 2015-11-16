#include "ihmObservable.hpp"
#include "ihmEvent.hpp"

using namespace ihm;

IHMObservable::IHMObservable()
{
}


IHMObservable::~IHMObservable()
{
}


void IHMObservable::registerObserver(IHMObserver* o) {

	observers.push_back(o);
}
void IHMObservable::unregisterObserver(IHMObserver* o) {

}
void IHMObservable::notifyObservers(const IHMEvent& e) {

	for(std::vector<IHMObserver*>::iterator observer = observers.begin(); observer != observers.end(); observer++)
	{
		(*observer)->ihmChanged(e);
	}
}

