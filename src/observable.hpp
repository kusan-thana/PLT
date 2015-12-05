#ifndef Observable_H
#define Observable_H
#include <vector>
#include "levelStateObserver.hpp"

namespace state {

class LevelStateEvent;

class Observable {

	protected:
		std::vector<state::LevelStateObserver*> observers;		//Mutable???
		
	public:
		virtual ~Observable();
		void registerObserver(LevelStateObserver* o);			//const??
		void notifyObservers(const LevelStateEvent& e);			//const??

};
}
#endif



